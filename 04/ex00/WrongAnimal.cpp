#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

WrongAnimal::WrongAnimal( void ) : type("WrongAnimal") { std::cerr << "WrongAnimal constructed\n"; }

WrongAnimal::~WrongAnimal( void ) { std::cerr << "WrongAnimal destructed\n"; }

std::string	WrongAnimal::getType( void ) const { return type; }

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal makes a noise\n";
}
