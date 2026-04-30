#include "Animal.hpp"
#include <string>
#include <iostream>

Animal::Animal( void ) : type("Animal") { std::cerr << "Animal constructed\n"; }

Animal::~Animal( void ) { std::cerr << "Animal destructed\n"; }

Animal::Animal( const Animal& toCopy )
{
	(void)toCopy;
	std::cerr << "Animal copied\n";
}

Animal&	Animal::operator=( const Animal& op )
{
	(void)op;
	std::cerr << "Animal assigned\n";
	return (*this);
}

std::string	Animal::getType( void ) const { return type; }

void	Animal::makeSound( void ) const
{
	std::cout << "Animal makes a noise\n";
}

Animal*	Animal::clone( void ) const
{
	return new Animal(*this);
}