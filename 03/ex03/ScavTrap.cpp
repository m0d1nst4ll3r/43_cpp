#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap( const std::string& name ) : ClapTrap(name)
{
	std::cerr << "ScavTrap: Constructor called\n";
	_hp = 100;
	_ep = 50;
	_dmg = 20;
	_guarding = false;
}

ScavTrap::ScavTrap( const ScavTrap& toCopy ) : ClapTrap(toCopy)
{
	std::cerr << "ScavTrap: Copy constructor called\n";
	_guarding = toCopy._guarding;
}

ScavTrap::~ScavTrap( void ) { std::cerr << "ScavTrap: Destructor called\n"; }

ScavTrap&	ScavTrap::operator=( const ScavTrap& op )
{
	std::cerr << "ScavTrap: Copy assignment operator overload called\n";
	if (this != &op)
	{
		ClapTrap::operator=(op);
		_guarding = op._guarding;
	}
	return *this;
}

void	ScavTrap::guardGate( void )
{
	if (!_guarding)
	{
		_guarding = true;
		std::cout << _name << " just entered Gate Keeper mode!\n";
	}
	else
		std::cout << _name << " is valiantly guarding the gate\n";
}

void	ScavTrap::attack( const std::string& target )
{
	if (_ep > 0)
	{
		_ep--;
		std::cout << _name
			<< " dropkicks " << target
			<< " in a spectacular fashion, causing " << _dmg
			<< " points of damage!";
		if (_dmg == 0)
			std::cout << " Lame.";
		std::cout << '\n';
	}
	else
		std::cout << _name << "'s all outta juice\n";
}
