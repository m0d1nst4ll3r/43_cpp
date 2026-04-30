#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

int	main( void )
{
	Cat	cat;
	Dog dog;
//	Animal	animal; // Does not compile

	cat.makeSound();
	dog.makeSound();
}
