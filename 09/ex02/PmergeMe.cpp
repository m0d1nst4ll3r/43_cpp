#include "PmergeMe.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <vector>
#include <list>
#include <algorithm>
#include <limits>

namespace
{
	bool	isInt(const char* str, unsigned int& val)
	{
		double res;

		for (int i = 0; str[i]; ++i)
		{
			if (!std::isdigit(str[i]))
				return false;
		}
		res = std::strtod(str, 0);
		val = static_cast<unsigned int>(res);
		return (res <= static_cast<double>(std::numeric_limits<unsigned int>::max())
				&& res >= static_cast<double>(std::numeric_limits<unsigned int>::min()));
	}

	template<typename InputIt> void printElems(InputIt first, InputIt last)
	{
		InputIt it = first;
		while (it != last)
		{
			std::cout << *it;
			it++;
			if (it != last)
				std::cout << ' ';
		}
	}

	// Ford-Johnson algorithm:
	// 1. Separate values in pairs (arbitrarily)
	//    In case of odd amount of values, leave one value unpaired
	// 2. Compare the lowest value in each pair, those are your "smaller" values (+ unpaired)
	//    The larger values in each pair are the "larger" ones
	// 3. Send the larger values to be sorted recursively by this algorithm
	//    The larger values are now sorted but each is still paired to its smaller one
	// 4. Insert smaller values in a specific order, through binary search
	//    Assuming indices 1, 2, 3, 4, 5, 6, 7, 8, 9, 10... in smaller values,
	//     insert in this order: 3, 2, 5, 4, 11, 10, 9, 8, 7, 6...
	//    This means insert (backwards) groups of 2, 2, 6, 10, 22, 42...
	//
	// Detailed explanation on step 4:
	// Binary search is comparing to the array's center value (N/2) then slicing the array
	//  in half and comparing against the relevant slice's center value (N/4 or 3N/4), etc...
	// This is most efficient when the array has the exact right amount of elements for this,
	//  e.g 3 elements (2 comparisons), or 7 (3 comparisons), or 15 (4 comparisons), or in
	//  short, (2^N - 1) for N comparisons.
	// Picture the values pairing where a are larger values and b smaller ones:
	// a1 -> a2 -> a3 -> a4 -> a5 -> a6 -> ... -> a(N/2)
	// |     |     |     |     |     |            |
	// b1    b2    b3    b4    b5    b6           b(N/2)  ... z (unpaired)
	// We know that b1 is necessarily smaller than a1, and so on... so we can picture a
	//  partially sorted chain:
	// b1 -> a1 -> a2 -> a3 -> a4 -> a5 -> a6 -> ... -> a(N/2)
	//             |     |     |     |     |            |
	//             b2    b3    b4    b5    b6           b(N/2)  ... z (unpaired)
	// We know b2 is less than a2, so to insert it we would have to compare against b1 and a1
	//  but it is more interesting to insert b3 which can be inserted by binary search since
	//  there are 3 values to compare it to (b1, a1, a2) for a cost of 2 comparisons. We THEN
	//  insert b2 which now has 3 values to compare to (b1, a1, b2) for a cost of 2.
	// c1 -> c2 -> c3 -> c4 -> c5 -> c6 -> a4 -> ... -> a(N/2)
	//                                     |            |
	//                                     b4           b(N/2)  ... z (unpaired)
	// For the next inserts, same thing: b4 would have 6 values (not 7), so we start with b5
	//  for a cost of 3, then b4 for a cost of 3. There are now 10 values to insert into for
	//  the next smaller value (b6), so we start inserting the 6th (b11, 15 values) for a
	//  cost of 4, then b10, then b9 etc.. for a constant cost of 4.
	// Keep going until all values are inserted. Always sort z last (unknown value).
	std::vector<unsigned int> sortVector()
	{
		std::vector<unsigned int>	vec;

		return vec;
	}

	std::list<unsigned int>	sortList()
	{
		std::list<unsigned int>	lst;

		return lst;
	}
}

PmergeMe::PmergeMe(char** args)
{
	if (args)
	{
		unsigned int	val;
		for (int i = 0; args[i]; ++i)
		{
			if (!isInt(args[i], val))
				throw std::runtime_error("'" + std::string(args[i]) + "' is not a positive integer");
			_toSort.push_back(val);
		}
	}
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& toCopy) : _toSort(toCopy._toSort) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& op)
{
	if (this != &op)
		_toSort = op._toSort;
	return *this;
}

void	PmergeMe::sort()
{
	if (_toSort.size() == 0)
		throw std::runtime_error("nothing to sort");

	// Unsure how to get time yet (in pdf, seems to be picoseconds)
	std::vector<unsigned int>	sortedVector;
	std::list<unsigned int>		sortedList;

	sortedVector = sortVector();
	sortedList = sortList();

	if (sortedVector.size() != sortedList.size() || !std::equal(sortedVector.begin(), sortedVector.end(), sortedList.begin()))
		throw std::runtime_error("unexpected difference in sorted arrays");

	std::cout << "Before:  \033[33m";
	printElems(_toSort.begin(), _toSort.end());
	std::cout << "\033[0m\n";
	std::cout << "After:   \033[33m";
	printElems(sortedVector.begin(), sortedVector.end());
	std::cout << "\033[0m\n";
	std::cout << "Time to process a range of \033[32m" << _toSort.size() << "\033[0m elements with \033[36mstd::vector\033[0m : " << "<WIP>\n";
	std::cout << "Time to process a range of \033[32m" << _toSort.size() << "\033[0m elements with \033[36mstd::list\033[0m   : " << "<WIP>\n";
}
