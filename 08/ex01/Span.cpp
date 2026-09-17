#include "Span.hpp"
#include <vector>
#include <algorithm>
#include <exception>
#include <limits>

Span::Span(unsigned int size) : _size(size), _shortest(-1), _longest(-1)
{
	_set.reserve(_size);
}

Span::~Span() {}
Span::Span(const Span& toCopy) : _set(toCopy._set), _size(toCopy._size), _shortest(toCopy._shortest), _longest(toCopy._longest) {}

Span&	Span::operator=(const Span& op)
{
	if (this != &op)
	{
		_set = op._set;
		_size = op._size;
		_shortest = op._shortest;
		_longest = op._longest;
	}
	return *this;
}

void	Span::addNumber(int n)
{
	if (_set.size() == _size)
		throw Span::MaximumSizeException();
	_set.push_back(n);
	_shortest = -1;
	_longest = -1;
}

long	Span::shortestSpan()
{
	if (_set.size() < 2)
		throw Span::TooFewNumbersException();
	if (_shortest == -1)
	{
		std::sort(_set.begin(), _set.end());
		_shortest = std::numeric_limits<long>::max();
		for (std::vector<int>::iterator it = _set.begin() + 1; it != _set.end(); ++it)
		{
			if (*it - *(it - 1) < _shortest)
				_shortest = *it - *(it - 1);
		}
	}
	return _shortest;
}

long	Span::longestSpan()
{
	if (_set.size() < 2)
		throw Span::TooFewNumbersException();
	if (_longest == -1)
		_longest = *std::max_element(_set.begin(), _set.end()) - *std::min_element(_set.begin(), _set.end());
	return _longest;
}

unsigned int	Span::getMaxSize() const { return _size; }
unsigned int	Span::getCurSize() const { return _set.size(); }

const char* Span::MaximumSizeException::what() const throw()
{
	return "maximum size reached";
}

const char* Span::TooFewNumbersException::what() const throw()
{
	return "not enough numbers to compute span";
}

const char* Span::BadRangeException::what() const throw()
{
	return "invalid range";
}
