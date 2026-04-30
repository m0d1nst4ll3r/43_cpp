#include "Animal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

Dog::Dog( void ) : Animal(), brain(new Brain())
{
	std::cerr << "Dog constructed\n";
	type = "Dog";
}

Dog::~Dog( void )
{
	delete brain;
	std::cerr << "Dog destructed\n";
}

Dog::Dog( const Dog& toCopy ) : Animal(toCopy), brain(new Brain(*toCopy.brain))
{
	std::cerr << "Dog copied\n";
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

Dog*	Dog::clone( void ) const
{
	return new Dog(*this);
}