#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap( void ) : _name("Default"), _hp(10), _ep(10), _dmg(0)
{
	std::cerr << "Default constructor called\n";
}

ClapTrap::ClapTrap( const std::string& name ) : _name(name), _hp(10), _ep(10), _dmg(0)
{
	std::cerr << "Name constructor called\n";
}

ClapTrap::ClapTrap( const ClapTrap& toCopy ) : _name(toCopy._name), _hp(10), _ep(10), _dmg(0)
{
	std::cerr << "Copy constructor called\n";
}

ClapTrap::~ClapTrap( void ) { std::cerr << "Destructor called\n"; }

ClapTrap&	ClapTrap::operator=( const ClapTrap& op )
{
	std::cerr << "Copy assignment operator overload called\n";
	if (this != &op)
	{
		_name = op._name;
		_hp = op._hp;
		_ep = op._ep;
		_dmg = op._dmg;
	}
	return *this;
}

void	ClapTrap::attack( const std::string& target )
{
	if (_ep > 0)
	{
		_ep--;
		std::cout << "ClapTrap " << _name
			<< " attacks " << target
			<< ", causing " << _dmg
			<< " points of damage!";
		if (_dmg == 0)
			std::cout << " Lame.";
		std::cout << '\n';
	}
	else
		std::cout << "ClapTrap " << _name << " has no energy to attack!\n";
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (_hp > 0)
	{
		std::cout << "ClapTrap " << _name << " took ";
		if (amount >= _hp)
		{
			std::cout << _hp << " points of damage and is down!\n";
			_hp = 0;
		}
		else
		{
			_hp -= amount;
			std::cout << amount << " points of damage and has "
				<< _hp << " remaining hit points. Ouch!\n";
		}
	}
	else
		std::cout << "ClapTrap " << _name
			<< " is already down. No use beating a dead horse!\n";
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (_ep > 0)
	{
		_ep--;
		_hp += amount;
		std::cout << "ClapTrap " << _name
			<< " repaired " << amount
			<< " hitpoints and has " << _hp
			<< " remaining!\n";
	}
	else
		std::cout << "ClapTrap " << _name << " has no energy to repair!\n";
}
