[Subject](https://cdn.intra.42.fr/pdf/pdf/214296/en.subject.pdf)

# ex02

This exercise requires a complete understanding of the Ford-Johnson algorithm. I couldn't find any satisfactory resource online, so I wrote up a basic explanation here. The only acceptable resource I found is [the book linked in the subject](https://seriouscomputerist.atariverse.com/media/pdf/book/Art%20of%20Computer%20Programming%20-%20Volume%203%20(Sorting%20&%20Searching).pdf) (page 196 of the pdf, 184 of the book), but it doesn't offer any help regarding the *implementation* of the algorithm.

### The Ford-Johnson algorithm (or merge-insertion sort):

The algorithm is a kind of recursive divide-and-conquer binary insertion sort. The gist of it is that we pair up values, sort these pairs to identify a winner (larger value) and a loser (smaller value) for each, recursively sort the array of winners, and then insert the losers back into the now-sorted array of winners in a specific order (Jacobsthal sequence) so that each inserted loser compares up to log(n) times thanks to binary insertion.

For reference, binary insertion is an algorithm to find where to insert a value in O(logn) comparisons. It requires searching into an already sorted set and chopping the set in half after each comparison. As an example, if you want to insert the value 8 in the sorted set {0, 2, 3, 5, 6, 7, 9}, you would first compare it against the middle value 5, then slice the set in half so that it becomes {6, 7, 9}, compare against 7, finally compare against 9, and insert at position 6.

The Jacobstahl sequence, on the other hands, is defined as 0 1 1 3 5 11 21 43 85... where J(n) = J(n-1) + J(n-2) * 2 and this is useful because it increases the number of elements to insert into by powers of 2, therefore optimizing the amount of comparisons that have to be made to insert a single element. The range of elements to insert into will grow like this: 3 7 15 31 63 127 255...

Here are the steps to the Ford-Johnson algorithm:

1. Separate values in pairs arbitrarily. In case of odd amount of values, leave one value unpaired.
2. Compare values in pairs and swap them as needed so that you have a set of winners (larger values) and losers (smaller ones).
3. Send the winners to be sorted recursively. The winners are now sorted and each is still attached to its loser.
4. Insert all losers along with the odd straggler back into the array of winners in a specific order, through binary search. Assuming a starting index of 0, insert losers in this order: 2, 1, 4, 3, 10, 9, 8, 7, 6, 5, 11... This means insert (backwards) groups of 2, 2, 6, 10, 22, 42...

To best understand step 4, look at the 3 pages of the book linked above. Here are some more explanations:

```
Binary search is comparing to the array's center value (n/2) then slicing the array in half
 and comparing against the relevant slice's center value (n/4 or 3n/4), etc...

This is most efficient when the array has the exact right amount of elements for this, e.g 3
 elements (2 comparisons), or 7 (3 comparisons), or 15 (4 comparisons), or in short,
 (2^n - 1) for n comparisons.

Picture the values pairing where `a1 ... a(n/2)` are larger values and `b1 ... b(n/2)`
 smaller ones:

a1 -> a2 -> a3 -> a4 -> a5 -> a6 -> ... -> a(n/2)
|     |     |     |     |     |            |
b1    b2    b3    b4    b5    b6           b(n/2)  ... z (unpaired)

We know that b1 is necessarily smaller than a1, and so on... so we can already picture a
 partially sorted chain:

b1 -> a1 -> a2 -> a3 -> a4 -> a5 -> a6 -> ... -> a(n/2)
            |     |     |     |     |            |
            b2    b3    b4    b5    b6           b(n/2)  ... z (unpaired)

We know b2 is less than a2, so to insert it we would have to compare against b1 and a1 but
 it is more interesting to insert b3 which can be inserted by binary search since there
 are 3 values to compare it to (b1, a1, a2) for a cost of 2 comparisons. We THEN insert
 b2 which now has (at most) 3 values to compare to (b1, a1, b2) for a cost of 2.

c1 -> c2 -> c3 -> c4 -> c5 -> c6 -> a4 -> ... -> a(n/2)
                                    |            |
                                    b4           b(n/2)  ... z (unpaired)

Since we just added 4 values to the chain of two that we had, we now have 6. For the next
 inserts, same thing: b4 would have 6 values (not 7), so we start with b5 for a cost of 3,
 then b4 for a (worst-case) cost of 3.

Now we've just added 4 new values to the chain, we now have 10, which is why we will skip
 the first 5 losers and go for the 6th, b11, which has 15 values to insert into, for a cost
 of 4, then b10, then b9 etc.. for a constant (worst-case) cost of 4 at every step.

We keep going like this until all values are inserted. We consider z to be the last "loser"
 as it is not paired with (inferior to) any other value.
```

### Implementation

This is the really difficult part, and I found absolutely 0 online resources for this. Being away from school and peers, I had to wrestle with an overclocked AI and my own brain for a while. This isn't guaranteed to be the best implementation, but it works.

Each task, taken individually, is relatively easy. Pairing values and comparing them is easy. So is designing a Jacobstahl progression loop, and so is binary insertion. The real difficulty for me was finding a viable way to structure data so that the array of winners could be sent down potentially infinite recursion and, when coming back up, still be paired to its losers, without infinite type nesting (pairs of pairs of pairs of pairs).

This is implemented here by the recursive function not returning a _sorted array of winner values_, but the sorted permutation of indices, then used to retro-actively sort the winners and losers. But since the recursive function doesn't care about returning values anymore with this change, even the arrays of winners/losers we sort with the permutation are not arrays of values, they are only arrays of indices (to be returned as the sorted permutation for the given array of values).

E.g if we send {3, 1, 2} the sort should return {1, 2, 0}, we will then know to push val[1] then val[2] then val[0] to obtain a sorted array. Therefore, the main function sends the complete set of values to be sorted recursively, but only gets back a set of indices. It has to sort the array itself.

Details of the implementation:
- Main func
1. Receive set of values in any form (currently, as vector).
2. Build set of values in required form (vector or deque).
3. Send set of values to recursion, receive permutation (in vector or deque).
4. Build the sorted set of values from unsorted set of values + permutation.
5. Return the sorted values (vector/deque) by copy.
- Recursive func
0. Receive only one value = end of recurse, return a container with only {0}.
1. Build pairs of indices by comparing actual values. This takes the form of 2 one dimension containers for simplicity.
2. Build unsorted set of larger values from set of larger indices + values. Send larger values to self, receive permutations.
3. Apply permutations to winner-loser indices pairs.
4. Insert losers in jacobstahl order through binary search.

Details of the insertion:
1. Save each winner's position in the array, starting at 1 2 3 4 ... n/2. This will be updated during insertion to know how to bound the binary search.
2. Insert first loser b1 (known to be <= a1)
3. Loop over losers in order 2 1 4 3 10 ... inserting each element

Details of step 3 (binary insertion):

Once we are able to loop over b3, b2, b5, b4, b11... in the right order, what remains is to know how to bound the binary insertion. When we insert b3, we want to compare it to values behind a3, as we already know b3 to be <= a3. For the very first insertion, we know where a3 is in the chain, but for the second, b2, we don't know for sure where a2 is as b3 might have been inserted before or after. Same for all remaining insertions.

This is why we build an array of positions, and update it when inserting.
