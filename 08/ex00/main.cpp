#include "easyfind.hpp"
#include <vector>
#include <iostream>

int	main()
{
	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	std::cout << "Searching for 1:\n";
	std::vector<int>::iterator it = easyfind(vec, 1);
	std::cout << "\t" << &*it << "\n";
	if (it != vec.end())
		std::cout << "\t" << *it << "\n";
	std::cout << "Searching for 3:\n";
	it = easyfind(vec, 3);
	std::cout << "\t" << &*it << "\n";
	if (it != vec.end())
		std::cout << "\t" << *it << "\n";
	std::cout << "Searching for 4:\n";
	it = easyfind(vec, 4);
	std::cout << "\t" << &*it << "\n";
	if (it != vec.end())
		std::cout << "\t" << *it << "\n";
	return 0;
}