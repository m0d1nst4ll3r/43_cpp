#include "Brain.hpp"
#include <string>
#include <iostream>

Brain::Brain( void )
{
	std::cerr << "Brain constructed\n";
}

Brain::~Brain( void )
{
	std::cerr << "Brain destructed\n";
}

Brain::Brain( const Brain& toCopy )
{
	std::cerr << "Brain copied\n";
	for (int i = 0; i < 100; ++i)
		ideas[i] = toCopy.ideas[i];
}

Brain&	Brain::operator=( const Brain& op )
{
	std::cerr << "Brain assigned\n";
	if (this != &op)
	{
		for (int i = 0; i < 100; ++i)
			ideas[i] = op.ideas[i];
	}
	return (*this);
}
