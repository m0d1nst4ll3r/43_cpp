#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

// If value is not found, returns an iterator pointing to the end of the data range
template<typename T> typename T::iterator easyfind(T& cont, int toFind)
{
	return (std::find(cont.begin(), cont.end(), toFind));
}

#endif /* EASYFIND_HPP */