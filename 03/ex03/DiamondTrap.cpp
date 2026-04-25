#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap( const std::string& name ) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cerr << "DiamondTrap: Constructor called\n";
	_hp = 100;
	_ep = 50;
	_dmg = 30;
}

DiamondTrap::DiamondTrap( const DiamondTrap& toCopy ) : ClapTrap(toCopy), ScavTrap(toCopy), FragTrap(toCopy), _name(toCopy._name)
{
	std::cerr << "DiamondTrap: Copy constructor called\n";
}

DiamondTrap::~DiamondTrap( void ) { std::cerr << "DiamondTrap: Destructor called\n"; }

DiamondTrap&	DiamondTrap::operator=( const DiamondTrap& op )
{
	std::cerr << "DiamondTrap: Copy assignment operator overload called\n";
	if (this != &op)
	{
		ScavTrap::operator=(op);
		_name = op._name;
	}
	return *this;
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "This bot is designated " << _name << " - [CL4PTR4P][" << ClapTrap::_name << "]\n";
}
