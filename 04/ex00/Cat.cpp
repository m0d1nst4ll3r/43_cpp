#include "Animal.hpp"
#include "Cat.hpp"
#include <string>
#include <iostream>

Cat::Cat( void ) : Animal()
{
	std::cerr << "Cat constructed\n";
	type = "Cat";
}

Cat::~Cat( void ) { std::cerr << "Cat destructed\n"; }

void	Cat::makeSound( void ) const
{
	std::cout << "Cat meows\n";
}

Cat::Cat( const Cat& toCopy )
{
	(void)toCopy;
	std::cerr << "Cat copied\n";
}

Cat&	Cat::operator=( const Cat& op )
{
	(void)op;
	std::cerr << "Cat assigned\n";
	return (*this);
}
