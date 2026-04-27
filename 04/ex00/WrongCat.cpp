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

WrongCat::WrongCat( const WrongCat& toCopy )
{
	(void)toCopy;
	std::cerr << "WrongCat copied\n";
}

WrongCat&	WrongCat::operator=( const WrongCat& op )
{
	(void)op;
	std::cerr << "WrongCat assigned\n";
	return (*this);
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "Cat meows\n";
}
