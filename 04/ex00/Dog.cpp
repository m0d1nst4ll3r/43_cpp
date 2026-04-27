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

Dog::Dog( const Dog& toCopy )
{
	(void)toCopy;
	std::cerr << "Dog copied\n";
}

Dog&	Dog::operator=( const Dog& op )
{
	(void)op;
	std::cerr << "Dog assigned\n";
	return (*this);
}
