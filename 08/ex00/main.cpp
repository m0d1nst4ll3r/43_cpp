#include "easyfind.hpp"
#include <vector>
#include <iostream>

int	main()
{
	std::vector<int> vec;

	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(1);
	std::vector<int>::iterator it = easyfind(vec, 4);
	std::cout << &it << "\n";
	if (it != vec.end())
		std::cout << *it << "\n";
	return 0;
}