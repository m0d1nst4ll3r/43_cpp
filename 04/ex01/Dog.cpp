#include "Animal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

Dog::Dog( void ) : Animal()
{
	std::cerr << "Dog constructed\n";
	type = "Dog";
	brain = new Brain();
}

Dog::~Dog( void )
{
	delete brain;
	std::cerr << "Dog destructed\n";
}

Dog::Dog( const Dog& toCopy ) : Animal(toCopy)
{
	std::cerr << "Dog copied\n";
	brain = toCopy.brain;
}

Dog&	Dog::operator=( const Dog& op )
{
	std::cerr << "Dog assigned\n";
	if (this != &op)
		brain = op.brain;
	return (*this);
}

void	Dog::makeSound( void ) const
{
	std::cout << "Dog barks\n";
}
