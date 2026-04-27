#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

int	main( void )
{
	Animal*	animArr[4];

	for (int i = 0; i < 4; ++i)
	{
		if (i % 2)
			animArr[i] = new Cat;
		else
			animArr[i] = new Dog;
	}

	std::cout << '\n';

	for (int i = 0; i < 4; ++i)
		delete animArr[i];
}
