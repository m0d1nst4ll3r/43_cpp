#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <exception>
#include <vector>
#include <cstdlib>
#include <sys/time.h>
#include <ctime>

namespace
{
	int	randomInt()
	{
		static bool	seeded = false;
		if (!seeded)
		{ // Combining tv_usec and std::clock for more randomness (this is overkill)
			struct timeval	tv;
			gettimeofday(&tv, NULL);
			srand(static_cast<unsigned int>(tv.tv_usec) ^ static_cast<unsigned int>(std::clock()));
			seeded = true;
		}
		return rand() % 2001 - 1000;
	}
}

int	main()
{
	std::cout << "Basic tests:\n";
	{
		Span	dfl;
		Span	span(5);

		std::cout << "\tdfl  max size: " << dfl.getMaxSize() << "\n";
		std::cout << "\tspan max size: " << span.getMaxSize() << "\n";
		std::cout << "\tspan cur size: " << span.getCurSize() << "\n";
		std::cout << "\tadding numbers 6, 3, 17...\n";
		span.addNumber(6);
		span.addNumber(3);
		span.addNumber(17);
		std::cout << "\tspan max size: " << span.getMaxSize() << "\n";
		std::cout << "\tspan cur size: " << span.getCurSize() << "\n";
		std::cout << "\tspan shortest: " << span.shortestSpan() << "\n";
		std::cout << "\tspan  longest: " << span.longestSpan() << "\n";
		std::cout << "\tadding numbers 9, 11...\n";
		span.addNumber(9);
		span.addNumber(11);
		std::cout << "\tspan max size: " << span.getMaxSize() << "\n";
		std::cout << "\tspan cur size: " << span.getCurSize() << "\n";
		std::cout << "\tspan shortest: " << span.shortestSpan() << "\n";
		std::cout << "\tspan  longest: " << span.longestSpan() << "\n";
		std::cout << "\tTrying to add number beyond limit...\n";
		try
		{
			span.addNumber(2);
		}
		catch (const std::exception& e)
		{
			std::cout << "\tFailed addNumber: " << e.what() << "\n";
		}
		std::cout << "\tTrying to get span from dfl...\n";
		try
		{
			dfl.shortestSpan();
		}
		catch (const std::exception& e)
		{
			std::cout << "\tFailed span: " << e.what() << "\n";
		}
		std::cout << "\tCopying:\n";
		Span	copy(span);
		std::cout << "\tcopy max size: " << copy.getMaxSize() << "\n";
		std::cout << "\tcopy cur size: " << copy.getCurSize() << "\n";
		std::cout << "\tcopy shortest: " << copy.shortestSpan() << "\n";
		std::cout << "\tcopy  longest: " << copy.longestSpan() << "\n";
		std::cout << "\tAssigning span to dfl:\n";
		dfl = span;
		std::cout << "\tdfl max size: " << dfl.getMaxSize() << "\n";
		std::cout << "\tdfl cur size: " << dfl.getCurSize() << "\n";
		std::cout << "\tdfl shortest: " << dfl.shortestSpan() << "\n";
		std::cout << "\tdfl  longest: " << dfl.longestSpan() << "\n";
	}
	std::cout << "Range add tests:\n";
	{
		int			arr[] = {6, 3, 17, 9, 11};
		std::vector<int>	vec;
		Span		spanArr(5);
		Span		spanVec(5);

		vec.push_back(6);
		vec.push_back(3);
		vec.push_back(17);
		vec.push_back(9);
		vec.push_back(11);
		std::cout << "\tBuilding span with vector:\n";
		spanVec.addRange(vec.begin(), vec.end());
		std::cout << "\tspanVec max size: " << spanVec.getMaxSize() << "\n";
		std::cout << "\tspanVec cur size: " << spanVec.getCurSize() << "\n";
		std::cout << "\tspanVec shortest: " << spanVec.shortestSpan() << "\n";
		std::cout << "\tspanVec  longest: " << spanVec.longestSpan() << "\n";
		std::cout << "\tBuilding span with array:\n";
		spanArr.addRange(arr, arr + 5);
		std::cout << "\tspanArr max size: " << spanArr.getMaxSize() << "\n";
		std::cout << "\tspanArr cur size: " << spanArr.getCurSize() << "\n";
		std::cout << "\tspanArr shortest: " << spanArr.shortestSpan() << "\n";
		std::cout << "\tspanArr  longest: " << spanArr.longestSpan() << "\n";
		std::cout << "\tTrying to add too many values...\n";
		try
		{
			spanArr.addRange(arr, arr + 5);
		}
		catch (const std::exception& e)
		{
			std::cout << "\tFailed addRange: " << e.what() << "\n";
		}
		std::cout << "\tTrying a bad range...\n";
		try
		{
			spanArr.addRange(arr + 5, arr);
		}
		catch (const std::exception& e)
		{
			std::cout << "\tFailed addRange: " << e.what() << "\n";
		}
	}
	std::cout << "Small test:\n";
	{
		Span				smallSpan(100);
		std::vector<int>	vec(100);

		std::generate(vec.begin(), vec.end(), randomInt);
		smallSpan.addRange(vec.begin(), vec.end());
		std::cout << "\tmin value: " << *std::min_element(vec.begin(), vec.end()) << "\n";
		std::cout << "\tmax value: " << *std::max_element(vec.begin(), vec.end()) << "\n";
		std::cout << "\tsmallSpan max size: " << smallSpan.getMaxSize() << "\n";
		std::cout << "\tsmallSpan cur size: " << smallSpan.getCurSize() << "\n";
		std::cout << "\tsmallSpan shortest: " << smallSpan.shortestSpan() << "\n";
		std::cout << "\tsmallSpan  longest: " << smallSpan.longestSpan() << "\n";
	}
	std::cout << "Medium test:\n";
	{
		Span				mediumSpan(1000);
		std::vector<int>	vec(1000);

		std::generate(vec.begin(), vec.end(), randomInt);
		mediumSpan.addRange(vec.begin(), vec.end());
		std::cout << "\tmin value: " << *std::min_element(vec.begin(), vec.end()) << "\n";
		std::cout << "\tmax value: " << *std::max_element(vec.begin(), vec.end()) << "\n";
		std::cout << "\tmediumSpan max size: " << mediumSpan.getMaxSize() << "\n";
		std::cout << "\tmediumSpan cur size: " << mediumSpan.getCurSize() << "\n";
		std::cout << "\tmediumSpan shortest: " << mediumSpan.shortestSpan() << "\n";
		std::cout << "\tmediumSpan  longest: " << mediumSpan.longestSpan() << "\n";
	}
	std::cout << "Big test:\n";
	{
		Span				bigSpan(10000);
		std::vector<int>	vec(10000);

		std::generate(vec.begin(), vec.end(), randomInt);
		bigSpan.addRange(vec.begin(), vec.end());
		std::cout << "\tmin value: " << *std::min_element(vec.begin(), vec.end()) << "\n";
		std::cout << "\tmax value: " << *std::max_element(vec.begin(), vec.end()) << "\n";
		std::cout << "\tbigSpan max size: " << bigSpan.getMaxSize() << "\n";
		std::cout << "\tbigSpan cur size: " << bigSpan.getCurSize() << "\n";
		std::cout << "\tbigSpan shortest: " << bigSpan.shortestSpan() << "\n";
		std::cout << "\tbigSpan  longest: " << bigSpan.longestSpan() << "\n";
	}
	return 0;
}