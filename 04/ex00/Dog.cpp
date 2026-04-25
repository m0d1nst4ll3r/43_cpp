#include "Animal.hpp"
#include "Dog.hpp"
#include <string>
#include <iostream>

Dog::Dog( void ) : Animal()
{
	std::cerr << "Dog constructed\n";
	type = "Dog";
}

Dog::~Dog( void ) { std::cerr << "Dog destructed\n"; }

void	Dog::makeSound( void ) const
{
	std::cout << "Dog barks\n";
}
