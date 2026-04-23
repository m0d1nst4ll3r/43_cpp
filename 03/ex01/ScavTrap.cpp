#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap( void ) : ClapTrap("Default", "ScavTrap")
{
	std::cerr << "ScavTrap: Default constructor called\n";
	this->setHp(100);
	this->setEp(50);
	this->setDmg(20);
	_guarding = false;
}

ScavTrap::ScavTrap( const std::string& name ) : ClapTrap(name, "ScavTrap")
{
	std::cerr << "ScavTrap: Name constructor called\n";
	this->setHp(100);
	this->setEp(50);
	this->setDmg(20);
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
		std::cout << "ScavTrap " << this->getName() << " starts guarding the gate\n";
	}
	else
		std::cout << "ScavTrap " << this->getName() << " is valiantly guarding the gate\n";
}
