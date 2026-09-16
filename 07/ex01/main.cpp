#include "iter.hpp"
#include <iostream>
#include <cstring>

template<typename T> void print(const T &a)
{
	std::cout << a;
}

template<typename T> void starify(T &a)
{
	a = 42;
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		std::cout << "String test:\n";
		std::cout << "\tBefore: ";
		iter(argv[1], strlen(argv[1]), print<char>);
		std::cout << "\n";
		iter(argv[1], strlen(argv[1]), starify<char>);
		std::cout << "\tAfter: ";
		iter(argv[1], strlen(argv[1]), print<char>);
		std::cout << "\n";
	}
	int arr[] = {1, 2, 3, 4, 5};
	std::cout << "Int test:\n";
	std::cout << "\tBefore: ";
	iter(arr, 5, print<int>);
	std::cout << "\n";
	iter(arr, 5, starify<int>);
	std::cout << "\tAfter: ";
	iter(arr, 5, print<int>);
	std::cout << "\n";
	return 0;
}