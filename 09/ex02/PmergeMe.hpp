#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe
{
	public:

	PmergeMe(char** args = 0); // Send argv + 1 from main
	~PmergeMe();
	PmergeMe(const PmergeMe& toCopy);
	PmergeMe& operator=(const PmergeMe& op);

	void sort(); // Sorts with vector/deque and prints analysis

	private:

	std::vector<unsigned int>	_sortVector() const;
	std::deque<unsigned int>	_sortDeque() const;

	std::vector<unsigned int>	_toSort; // Only ever used to fill containers
};

#endif /* PMERGEME_HPP */
