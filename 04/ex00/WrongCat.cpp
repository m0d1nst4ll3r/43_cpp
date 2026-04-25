#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <string>
#include <iostream>

WrongCat::WrongCat( void ) : WrongAnimal()
{
	std::cerr << "WrongCat constructed\n";
	type = "Cat";
}

WrongCat::~WrongCat( void ) { std::cerr << "WrongCat destructed\n"; }

void	WrongCat::makeSound( void ) const
{
	std::cout << "Cat meows\n";
}
