#include "Weapon.hpp"
#include "HumanA.hpp"
#include <iostream>
#include <string>

HumanA::HumanA( const std::string& name, Weapon& weapon ) : name(name), weapon(weapon) {}

void	HumanA::attack( void )
{
	std::cout << name << " attacks with their " << weapon.getType() << "\n";
}
