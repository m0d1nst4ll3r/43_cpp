#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span
{
	public:

	class MaximumSizeException : public std::exception
	{
		public:
		const char* what() const throw();
	};

	class TooFewNumbersException : public std::exception
	{
		public:
		const char* what() const throw();
	};

	class BadRangeException : public std::exception
	{
		public:
		const char* what() const throw();
	};

	Span(unsigned int size = 0);
	~Span();
	Span(const Span& toCopy);
	Span&	operator=(const Span& op);

	void	addNumber(int n);

	template<typename RandomAccessIterator>void addRange(RandomAccessIterator first, RandomAccessIterator last)
	{
		if (last < first)
			throw Span::BadRangeException();
		if (_set.size() + (last - first) > _size)
			throw Span::MaximumSizeException();
		_set.insert(_set.end(), first, last);
		_shortest = -1;
		_longest = -1;
	}

	long	shortestSpan();
	long	longestSpan();

	unsigned int	getMaxSize() const;
	unsigned int	getCurSize() const;

	private:

	std::vector<int>	_set;
	unsigned int		_size;
	long				_shortest; // used to memorize previous span compute results
	long				_longest;  // -1 if there is no previous compute, or previous compute needs updating
};

#endif /* SPAN_HPP */
