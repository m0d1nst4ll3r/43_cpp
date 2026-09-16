#include "Array.hpp"
#include <iostream>
#include <exception>
#include <string>

int	main()
{
	std::cout << "Int test:\n";
	{ // int
		Array<int> empty;
		Array<int> arr(2);
		std::cout << "\tSize of empty array: " << empty.size() << "\n";
		std::cout << "\tSize of array: " << arr.size() << "\n";
		try
		{
			empty[0] = 2;
		}
		catch(std::exception& e)
		{
			std::cerr << "\tEmpty array assign failed: " << e.what() << '\n';
		}
		try
		{
			std::cout << empty[-2] << "\n";
		}
		catch(std::exception& e)
		{
			std::cerr << "\tEmpty array access failed: " << e.what() << '\n';
		}
		arr[0] = 10;
		arr[1] = 42;
		Array<int> copy(arr);
		std::cout << "\tOriginal: " << arr[0] << ", " << arr[1] << "\n";
		std::cout << "\tCopy:     " << copy[0] << ", " << copy[1] << "\n";
		std::cout << "\tSize of copy: " << copy.size() << "\n";
		std::cout << "\tChanging copy...\n";
		copy[0] = 50;
		std::cout << "\tOriginal: " << arr[0] << ", " << arr[1] << "\n";
		std::cout << "\tCopy:     " << copy[0] << ", " << copy[1] << "\n";
		std::cout << "\tCopying original...\n";
		arr = copy;
		std::cout << "\tOriginal: " << arr[0] << ", " << arr[1] << "\n";
		std::cout << "\tCopy:     " << copy[0] << ", " << copy[1] << "\n";
		std::cout << "\tCreating new array of size 5 then copying...\n";
		Array<int> diffSize(5);
		diffSize = copy;
		std::cout << "\tCopy #2:   " << diffSize[0] << ", " << diffSize[1] << "\n";
		std::cout << "\tSize of copy #2: " << diffSize.size() << "\n";
	}
	std::cout << "String test:\n";
	{ // int
		Array<std::string> empty;
		Array<std::string> arr(2);
		std::cout << "\tSize of empty array: " << empty.size() << "\n";
		std::cout << "\tSize of array: " << arr.size() << "\n";
		try
		{
			empty[0] = "42";
		}
		catch(std::exception& e)
		{
			std::cerr << "\tEmpty array assign failed: " << e.what() << '\n';
		}
		try
		{
			std::cout << empty[-2] << "\n";
		}
		catch(std::exception& e)
		{
			std::cerr << "\tEmpty array access failed: " << e.what() << '\n';
		}
		arr[0] = "Salut";
		arr[1] = "Hello";
		Array<std::string> copy(arr);
		std::cout << "\tOriginal: " << arr[0] << ", " << arr[1] << "\n";
		std::cout << "\tCopy:     " << copy[0] << ", " << copy[1] << "\n";
		std::cout << "\tSize of copy: " << copy.size() << "\n";
		std::cout << "\tChanging copy...\n";
		copy[0] = "Pouet";
		std::cout << "\tOriginal: " << arr[0] << ", " << arr[1] << "\n";
		std::cout << "\tCopy:     " << copy[0] << ", " << copy[1] << "\n";
		std::cout << "\tCopying original...\n";
		arr = copy;
		std::cout << "\tOriginal: " << arr[0] << ", " << arr[1] << "\n";
		std::cout << "\tCopy:     " << copy[0] << ", " << copy[1] << "\n";
		std::cout << "\tCreating new array of size 5 then copying...\n";
		Array<std::string> diffSize(5);
		diffSize = copy;
		std::cout << "\tCopy #2:   " << diffSize[0] << ", " << diffSize[1] << "\n";
		std::cout << "\tSize of copy #2: " << diffSize.size() << "\n";
	}
	return 0;
}