#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie( void ) {}

Zombie::Zombie( const std::string& name ) : _name(name) {}

Zombie::~Zombie( void )
{
	std::cout << _name << " took a bullet to the brain.\n";
}

void	Zombie::setName( const std::string& name )
{
	_name = name;
}

void	Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}
