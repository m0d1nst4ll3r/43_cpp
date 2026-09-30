#include "PmergeMe.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <vector>
#include <deque>
#include <algorithm>
#include <limits>
#include <sys/time.h>

namespace
{
	long	getTime()
	{
		struct timeval	tv;

		gettimeofday(&tv, 0);
		return (1000000 * tv.tv_sec + tv.tv_usec);
	}

	// Used in construction
	bool	isInt(const char* str, unsigned int& val)
	{
		if (!*str)
			return false;

		double res;

		for (int i = 0; str[i]; ++i)
		{
			if (!std::isdigit(static_cast<unsigned char>(str[i])))
				return false;
		}
		res = std::strtod(str, 0);
		val = static_cast<unsigned int>(res);
		return (res <= static_cast<double>(std::numeric_limits<unsigned int>::max())
				&& res >= static_cast<double>(std::numeric_limits<unsigned int>::min()));
	}

	// Used in "Before/After" prints
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

	std::vector<unsigned int> recurseVector(std::vector<unsigned int> values)
	{
		// Step 0: end of recurse
		if (values.size() == 1) // cannot be 0 for our usecase
			return std::vector<unsigned int>(1, 0);

		// Constants
		const unsigned int	n = values.size();
		const unsigned int	m = n / 2; // number of pairs
		const bool			odd = n % 2;
		const unsigned int	stragglerIdx = n - 1; // unpaired value

		// Step 1: build pairs
		std::vector<unsigned int> winnerIdx;
		std::vector<unsigned int> loserIdx;
		winnerIdx.reserve(m);
		loserIdx.reserve(m);

		for (unsigned int i = 0; i < m; ++i)
		{
			unsigned int left = i * 2;
			unsigned int right = i * 2 + 1;
			if (values[left] < values[right]) // order winner-losers
			{
				winnerIdx.push_back(right);
				loserIdx.push_back(left);
			}
			else
			{
				winnerIdx.push_back(left);
				loserIdx.push_back(right);
			}
		}

		// Step 2: build winner values, send to recurse
		std::vector<unsigned int> winnerValues;
		winnerValues.reserve(m);
		for (unsigned int i = 0; i < m; ++i) winnerValues.push_back(values[winnerIdx[i]]);
		std::vector<unsigned int> winnerOrder = recurseVector(winnerValues);

		// Step 3: re-order pairs
		std::vector<unsigned int> sortedWinnerIdx;
		std::vector<unsigned int> sortedLoserIdx;
		sortedWinnerIdx.reserve(n);
		sortedLoserIdx.reserve(m);

		for (unsigned int i = 0; i < m; ++i)
		{
			sortedWinnerIdx.push_back(winnerIdx[winnerOrder[i]]);
			sortedLoserIdx.push_back(loserIdx[winnerOrder[i]]);
		}

		// Step 4: insert losers back
		// Build winner positions, starting out as 1 2 3 4 5 6 7 8...
		std::vector<unsigned int> winnerPos;
		winnerPos.reserve(m);
		for (unsigned int i = 0; i < m; ++i) winnerPos.push_back(i + 1);

		// Insert first loser (guaranteed to be there)
		sortedWinnerIdx.insert(sortedWinnerIdx.begin(), sortedLoserIdx[0]);

		unsigned int tmp;
		unsigned int lower = 0;
		unsigned int upper = 2;
		unsigned int idx = std::min(upper, m + odd - 1);
		while (lower < m + odd - 1)
		{
			// Find binary search boundaries
			unsigned int lo = 0;
			unsigned int hi;
			unsigned int elemIdx;
			if (idx < m)
			{
				elemIdx = sortedLoserIdx[idx];
				hi = winnerPos[idx];
			}
			else // Straggler case (unpaired value)
			{
				elemIdx = stragglerIdx;
				hi = sortedWinnerIdx.size();
			}
			// Execute binary search
			while (lo < hi)
			{
				unsigned int mid = (hi + lo) / 2;
				if (values[elemIdx] < values[sortedWinnerIdx[mid]])
					hi = mid;
				else
					lo = mid + 1;
			}
			// Insert elem
			sortedWinnerIdx.insert(sortedWinnerIdx.begin() + lo, elemIdx);
			// Update winner pos
			for (unsigned int i = 0; i < m; ++i)
			{
				if (winnerPos[i] >= lo)
					winnerPos[i]++;
			}
			idx--;
			if (idx == lower)
			{
				tmp = lower;
				lower = upper;
				upper += (tmp + 1) * 2;
				idx = std::min(upper, m + odd - 1);
			}
		}
		return sortedWinnerIdx;
	}

	std::deque<unsigned int> recurseDeque(std::deque<unsigned int> values)
	{
		if (values.size() == 1)
			return std::deque<unsigned int>(1, 0);

		const unsigned int	n = values.size();
		const unsigned int	m = n / 2;
		const bool			odd = n % 2;
		const unsigned int	stragglerIdx = n - 1;

		std::deque<unsigned int> winnerIdx;
		std::deque<unsigned int> loserIdx;

		for (unsigned int i = 0; i < m; ++i)
		{
			unsigned int left = i * 2;
			unsigned int right = i * 2 + 1;
			if (values[left] < values[right])
			{
				winnerIdx.push_back(right);
				loserIdx.push_back(left);
			}
			else
			{
				winnerIdx.push_back(left);
				loserIdx.push_back(right);
			}
		}

		std::deque<unsigned int> winnerValues;
		for (unsigned int i = 0; i < m; ++i) winnerValues.push_back(values[winnerIdx[i]]);
		std::deque<unsigned int> winnerOrder = recurseDeque(winnerValues);

		std::deque<unsigned int> sortedWinnerIdx;
		std::deque<unsigned int> sortedLoserIdx;

		for (unsigned int i = 0; i < m; ++i)
		{
			sortedWinnerIdx.push_back(winnerIdx[winnerOrder[i]]);
			sortedLoserIdx.push_back(loserIdx[winnerOrder[i]]);
		}

		std::deque<unsigned int> winnerPos;
		for (unsigned int i = 0; i < m; ++i) winnerPos.push_back(i + 1);

		sortedWinnerIdx.push_front(sortedLoserIdx[0]);

		unsigned int tmp;
		unsigned int lower = 0;
		unsigned int upper = 2;
		unsigned int idx = std::min(upper, m + odd - 1);
		while (lower < m + odd - 1)
		{
			unsigned int lo = 0;
			unsigned int hi;
			unsigned int elemIdx;
			if (idx < m)
			{
				elemIdx = sortedLoserIdx[idx];
				hi = winnerPos[idx];
			}
			else
			{
				elemIdx = stragglerIdx;
				hi = sortedWinnerIdx.size();
			}
			while (lo < hi)
			{
				unsigned int mid = (hi + lo) / 2;
				if (values[elemIdx] < values[sortedWinnerIdx[mid]])
					hi = mid;
				else
					lo = mid + 1;
			}
			sortedWinnerIdx.insert(sortedWinnerIdx.begin() + lo, elemIdx);
			for (unsigned int i = 0; i < m; ++i)
			{
				if (winnerPos[i] >= lo)
					winnerPos[i]++;
			}
			idx--;
			if (idx == lower)
			{
				tmp = lower;
				lower = upper;
				upper += (tmp + 1) * 2;
				idx = std::min(upper, m + odd - 1);
			}
		}
		return sortedWinnerIdx;
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

std::vector<unsigned int> PmergeMe::_sortVector() const
{
	std::vector<unsigned int>	unsorted;
	std::vector<unsigned int>	perm;
	std::vector<unsigned int>	sorted;

	// Build from _toSort
	unsorted.insert(unsorted.end(), _toSort.begin(), _toSort.end());
	// Recurse, get permutation back
	perm = recurseVector(unsorted);
	// Apply permutation
	for (std::vector<unsigned int>::iterator it = perm.begin(); it != perm.end(); ++it)
		sorted.push_back(unsorted[*it]);

	return sorted;
}

std::deque<unsigned int> PmergeMe::_sortDeque() const
{
	std::deque<unsigned int>	unsorted;
	std::deque<unsigned int>	perm;
	std::deque<unsigned int>	sorted;

	unsorted.insert(unsorted.end(), _toSort.begin(), _toSort.end());
	perm = recurseDeque(unsorted);
	for (std::deque<unsigned int>::iterator it = perm.begin(); it != perm.end(); ++it)
		sorted.push_back(unsorted[*it]);

	return sorted;
}

void	PmergeMe::sort()
{
	if (_toSort.size() == 0)
		throw std::runtime_error("nothing to sort");

	// Unsure how to get time yet (in pdf, seems to be picoseconds)
	std::vector<unsigned int>	sortedVector;
	std::deque<unsigned int>	sortedDeque;
	long	timeStart;
	long	timeVector;
	long	timeDeque;

	timeStart = getTime();
	sortedVector = _sortVector();
	timeVector = getTime() - timeStart;

	timeStart = getTime();
	sortedDeque = _sortDeque();
	timeDeque = getTime() - timeStart;

	if (sortedVector.size() != sortedDeque.size() || !std::equal(sortedVector.begin(), sortedVector.end(), sortedDeque.begin()))
		throw std::runtime_error("unexpected difference in sorted arrays");

	if (std::adjacent_find(sortedVector.begin(), sortedVector.end(), std::greater<unsigned int>()) != sortedVector.end())
		throw std::runtime_error("unexpected failure: array is not sorted");

	std::cout << "Before:  \033[33m";
	printElems(_toSort.begin(), _toSort.end());
	std::cout << "\033[0m\n";
	std::cout << "After:   \033[33m";
	printElems(sortedVector.begin(), sortedVector.end());
	std::cout << "\033[0m\n";
	std::cout << "Time to process a range of \033[32m" << _toSort.size() << "\033[0m elements with \033[36mstd::vector\033[0m : " << timeVector << "us\n";
	std::cout << "Time to process a range of \033[32m" << _toSort.size() << "\033[0m elements with \033[36mstd::deque\033[0m  : " << timeDeque << "us\n";
}
