#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

Cat::Cat( void ) : Animal()
{
	std::cerr << "Cat constructed\n";
	type = "Cat";
	brain = new Brain();
}

Cat::~Cat( void )
{
	delete brain;
	std::cerr << "Cat destructed\n";
}

Cat::Cat( const Cat& toCopy ) : Animal(toCopy)
{
	std::cerr << "Cat copied\n";
	brain = toCopy.brain;
}

Cat&	Cat::operator=( const Cat& op )
{
	std::cerr << "Cat assigned\n";
	if (this != &op)
		brain = op.brain;
	return (*this);
}

void	Cat::makeSound( void ) const
{
	std::cout << "Cat meows\n";
}
