#include "Animal.hpp"
#include <string>
#include <iostream>

Animal::Animal( void ) : type("Animal") { std::cerr << "Animal constructed\n"; }

Animal::~Animal( void ) { std::cerr << "Animal destructed\n"; }

std::string	Animal::getType( void ) const { return type; }

void	Animal::makeSound( void ) const
{
	std::cout << "Animal makes a noise\n";
}
