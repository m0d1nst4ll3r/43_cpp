#include "PmergeMe.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <vector>
#include <deque>
#include <algorithm>
#include <limits>
#include <ctime>

namespace
{

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

	// Sorts values directly instead of returning a fresh vector
	void recurseVector(std::vector<unsigned int>& values, unsigned int blockSize)
	{
		const unsigned int	n = values.size();
		const unsigned int	pairSize = blockSize * 2;
		const unsigned int	pairs = n / pairSize;
		const bool			straggler = (n >= pairs * pairSize + blockSize);
		const unsigned int	losers = pairs - 1 + straggler;

		// Step 0: Recursion end
		if (n < pairSize)
			return ;

		// Step 1: Compare blocks and order winner-losers (straggler block + tail are untouched)
		for (unsigned int i = 0; i < pairs; ++i)
		{
			if (values[i * pairSize] < values[i * pairSize + blockSize]) // Compare 1st value of each block
			{
				for (unsigned int j = 0; j < blockSize; ++j) // Swap blocks
					std::swap(values[i * pairSize + j], values[i * pairSize + blockSize + j]);
			}
		}

		// Step 2: Recurse to sort the pairs
		recurseVector(values, blockSize * 2);

		// Step 3: Insert winner values into fresh vector
		// Create fresh vector
		std::vector<unsigned int>	sorted;
		sorted.reserve(n);
		// Insert b1 block
		sorted.insert(sorted.end(), values.begin() + blockSize, values.begin() + pairSize);
		// Insert winners a1, a2, a3... a(pairs)
		for (unsigned int i = 0; i < pairs; ++i)
			sorted.insert(sorted.end(), values.begin() + i * pairSize, values.begin() + i * pairSize + blockSize);

		// Step 4: Insert loser values in Jacobsthal order
		// Insert losers
		unsigned int	lower = 0; // Lower bound of current Jacobsthal block ([0-2] -> [2-4] -> [4-10] --|)
		unsigned int	upper = 2; // Upper bound --------------------------- (...<- [42-20] <- [10-20] <-|)
		unsigned int	insert = 4; // Size of binary search (3 -> 7 -> 15 -> 31 -> 63 -> ...)
		unsigned int	loserVirtualIdx = std::min(upper, pairs - 1 + straggler); // Virtual index (2 -> 1 -> 4 -> 3 -> 10 -> 9 -> ...)
		while (lower < pairs - 1 + straggler)
		{
			// Find binary search boundaries
			unsigned int lo = 0;
			unsigned int hi;
			unsigned int loserRealIdx; // Real index (in values[], accounting for blockSize)
			if (loserVirtualIdx < pairs) // Loser is paired with winner
			{
				loserRealIdx = loserVirtualIdx * pairSize + blockSize;
				hi = std::min(insert - 1, static_cast<unsigned int>(sorted.size() / blockSize));
			}
			else // Loser is straggler (unpaired)
			{
				loserRealIdx = loserVirtualIdx * pairSize; // No paired winner block
				hi = sorted.size() / blockSize;
			}
			// Execute binary search
			while (lo < hi)
			{
				unsigned int mid = (lo + hi) / 2;
				if (values[loserRealIdx] < sorted[mid * blockSize]) // Compare loser to 1st value of block
					hi = mid;
				else
					lo = mid + 1;
			}
			// Insert loser block
			sorted.insert(sorted.begin() + lo * blockSize, values.begin() + loserRealIdx, values.begin() + loserRealIdx + blockSize);
			// Idx works backwards (2 -> 1 -> 4 -> 3 -> 10 -> 9 -> 8 -> 7 -> ...)
			loserVirtualIdx--;
			// If Jacobstahl block is completed, go to next block (2 -> 2 -> 6 -> 10 -> 22 -> ...)
			if (loserVirtualIdx == lower)
			{
				unsigned int tmp = lower;
				lower = upper;
				upper += (tmp + 1) * 2;
				loserVirtualIdx = std::min(upper, losers);
				insert *= 2;
			}
		}
		// Append tail (for last elems < blockSize)
		sorted.insert(sorted.end(), values.begin() + pairs * pairSize + straggler * blockSize, values.end());

		// Done: replace old vector
		values = sorted;
	}

	void recurseDeque(std::deque<unsigned int>& values, unsigned int blockSize)
	{
		const unsigned int	n = values.size();
		const unsigned int	pairSize = blockSize * 2;
		const unsigned int	pairs = n / pairSize;
		const bool			straggler = (n >= pairs * pairSize + blockSize);
		const unsigned int	losers = pairs - 1 + straggler;

		if (n < pairSize)
			return ;

		for (unsigned int i = 0; i < pairs; ++i)
		{
			if (values[i * pairSize] < values[i * pairSize + blockSize])
			{
				for (unsigned int j = 0; j < blockSize; ++j) // Swap blocks
					std::swap(values[i * pairSize + j], values[i * pairSize + blockSize + j]);
			}
		}

		recurseDeque(values, blockSize * 2);

		std::deque<unsigned int>	sorted;
		sorted.insert(sorted.end(), values.begin() + blockSize, values.begin() + pairSize);
		for (unsigned int i = 0; i < pairs; ++i)
			sorted.insert(sorted.end(), values.begin() + i * pairSize, values.begin() + i * pairSize + blockSize);

		unsigned int	lower = 0;
		unsigned int	upper = 2;
		unsigned int	insert = 4;
		unsigned int	loserVirtualIdx = std::min(upper, pairs - 1 + straggler);
		while (lower < pairs - 1 + straggler)
		{
			unsigned int lo = 0;
			unsigned int hi;
			unsigned int loserRealIdx;
			if (loserVirtualIdx < pairs)
			{
				loserRealIdx = loserVirtualIdx * pairSize + blockSize;
				hi = std::min(insert - 1, static_cast<unsigned int>(sorted.size() / blockSize));
			}
			else
			{
				loserRealIdx = loserVirtualIdx * pairSize; // No paired winner block
				hi = sorted.size() / blockSize;
			}
			while (lo < hi)
			{
				unsigned int mid = (lo + hi) / 2;
				if (values[loserRealIdx] < sorted[mid * blockSize])
					hi = mid;
				else
					lo = mid + 1;
			}
			sorted.insert(sorted.begin() + lo * blockSize, values.begin() + loserRealIdx, values.begin() + loserRealIdx + blockSize);
			loserVirtualIdx--;
			if (loserVirtualIdx == lower)
			{
				unsigned int tmp = lower;
				lower = upper;
				upper += (tmp + 1) * 2;
				loserVirtualIdx = std::min(upper, losers);
				insert *= 2;
			}
		}
		sorted.insert(sorted.end(), values.begin() + pairs * pairSize + straggler * blockSize, values.end());

		values = sorted;
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
	std::vector<unsigned int>	vec;

	// Build from _toSort
	vec.insert(vec.end(), _toSort.begin(), _toSort.end());
	recurseVector(vec, 1);
	return vec;
}

std::deque<unsigned int> PmergeMe::_sortDeque() const
{
	std::deque<unsigned int>	deq;

	deq.insert(deq.end(), _toSort.begin(), _toSort.end());
	recurseDeque(deq, 1);
	return deq;
}

void	PmergeMe::sort()
{
	if (_toSort.size() == 0)
		throw std::runtime_error("nothing to sort");

	// Unsure how to get time yet (in pdf, seems to be picoseconds)
	std::vector<unsigned int>	sortedVector;
	std::deque<unsigned int>	sortedDeque;
	std::clock_t	timeVector;
	std::clock_t	timeDeque;

	timeVector = std::clock();
	sortedVector = _sortVector();
	timeVector = std::clock() - timeVector;

	timeDeque = std::clock();
	sortedDeque = _sortDeque();
	timeDeque = std::clock() - timeDeque;

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
	std::cout << "Time to process a range of \033[32m" << _toSort.size() << "\033[0m elements with \033[36mstd::vector\033[0m : "
	<< static_cast<long>(static_cast<double>(timeVector) * 1000000 / CLOCKS_PER_SEC) << "us\n";
	std::cout << "Time to process a range of \033[32m" << _toSort.size() << "\033[0m elements with \033[36mstd::deque\033[0m  : "
	<< static_cast<long>(static_cast<double>(timeDeque) * 1000000 / CLOCKS_PER_SEC) << "us\n";
}
