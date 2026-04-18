#include "Weapon.hpp"
#include "HumanB.hpp"
#include <iostream>
#include <string>

HumanB::HumanB( const std::string& name )
	: name(name)
{
	weapon = NULL;
}

void	HumanB::setWeapon( Weapon& weapon )
{
	this->weapon = &weapon;
}

void	HumanB::attack( void )
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << "\n";
	else
		std::cout << name << " has no weapon";
}
