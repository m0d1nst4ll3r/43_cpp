#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

Cat::Cat( void ) : Animal(), brain(new Brain())
{
	std::cerr << "Cat constructed\n";
	type = "Cat";
}

Cat::~Cat( void )
{
	delete brain;
	std::cerr << "Cat destructed\n";
}

Cat::Cat( const Cat& toCopy ) : Animal(toCopy), brain(new Brain(*toCopy.brain))
{
	std::cerr << "Cat copied\n";
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

Cat*	Cat::clone( void ) const
{
	return new Cat(*this);
}