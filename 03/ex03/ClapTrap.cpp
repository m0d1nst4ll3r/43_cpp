#include "ClapTrap.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

ClapTrap::ClapTrap( const std::string& name ) : _name(name), _hp(10), _ep(10), _dmg(0)
{
	std::cerr << "ClapTrap: Constructor called\n";
}

ClapTrap::ClapTrap( const ClapTrap& toCopy ) : _name(toCopy._name), _hp(toCopy._hp), _ep(toCopy._ep), _dmg(toCopy._dmg)
{
	std::cerr << "ClapTrap: Copy constructor called\n";
}

ClapTrap::~ClapTrap( void ) { std::cerr << "ClapTrap: Destructor called\n"; }

ClapTrap&	ClapTrap::operator=( const ClapTrap& op )
{
	std::cerr << "ClapTrap: Copy assignment operator overload called\n";
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
		std::cout << _name
			<< " attacks " << target
			<< ", causing " << _dmg
			<< " points of damage!";
		if (_dmg == 0)
			std::cout << " Lame.";
		std::cout << '\n';
	}
	else
		std::cout << _name << " has no energy to attack!\n";
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (_hp > 0)
	{
		std::cout << _name << " took ";
		if (amount >= _hp)
		{
			std::cout << _hp << " points of damage and is down!\n";
			_hp = 0;
		}
		else
		{
			_hp -= amount;
			std::cout << amount << " points of damage and has "
				<< _hp << " remaining hit points. ";
			if (!amount)
				std::cout << "Phew!\n";
			else
			{
				int rand = std::rand() % 6;
				switch (rand)
				{
					case 0:
						std::cout << "Ouch!\n";
						break;
					case 1:
						std::cout << "Oof!\n";
						break;
					case 2:
						std::cout << "Wham!\n";
						break;
					case 3:
						std::cout << "Blam!\n";
						break;
					case 4:
						std::cout << "Fzzt!\n";
						break;
					default:
						std::cout << "Bzzt!\n";
				}
			}
		}
	}
	else
		std::cout << _name
			<< " is already down. No use beating a dead bot!\n";
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (_ep > 0)
	{
		_ep--;
		_hp += amount;
		std::cout << _name
			<< " repaired " << amount
			<< " hitpoints and has " << _hp
			<< " remaining!\n";
	}
	else
		std::cout << _name << " has no energy to repair!\n";
}
