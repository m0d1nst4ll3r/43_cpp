#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>

class PmergeMe
{
	public:

	PmergeMe(char** args = 0); // Send argv + 1 from main
	~PmergeMe();
	PmergeMe(const PmergeMe& toCopy);
	PmergeMe& operator=(const PmergeMe& op);

	void sort(); // Sorts with vector/list and prints analysis

	private:

	std::vector<unsigned int>	_toSort; // vector sorting does not use this directly (like list)
};

#endif /* PMERGEME_HPP */
