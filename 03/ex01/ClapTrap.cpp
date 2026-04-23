#include "ClapTrap.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

ClapTrap::ClapTrap( void ) : _typeName("ClapTrap"), _name("Default"), _hp(10), _ep(10), _dmg(0)
{
	std::cerr << "ClapTrap: Default constructor called\n";
}

ClapTrap::ClapTrap( const std::string& name ) : _typeName("ClapTrap"), _name(name), _hp(10), _ep(10), _dmg(0)
{
	std::cerr << "ClapTrap: Name constructor called\n";
}

ClapTrap::ClapTrap( const std::string& name, const std::string& typeName ) : _typeName(typeName), _name(name), _hp(10), _ep(10), _dmg(0)
{
	std::cerr << "ClapTrap: Name+Type constructor called\n";
}

ClapTrap::ClapTrap( const ClapTrap& toCopy ) : _typeName(toCopy._typeName), _name(toCopy._name), _hp(toCopy._hp), _ep(toCopy._ep), _dmg(toCopy._dmg)
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
		std::cout << _typeName << " " << _name
			<< " attacks " << target
			<< ", causing " << _dmg
			<< " points of damage!";
		if (_dmg == 0)
			std::cout << " Lame.";
		std::cout << '\n';
	}
	else
		std::cout << _typeName << " " << _name << " has no energy to attack!\n";
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (_hp > 0)
	{
		std::cout << _typeName << " " << _name << " took ";
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
	else
		std::cout << _typeName << " " << _name
			<< " is already down. No use beating a dead bot!\n";
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (_ep > 0)
	{
		_ep--;
		_hp += amount;
		std::cout << _typeName << " " << _name
			<< " repaired " << amount
			<< " hitpoints and has " << _hp
			<< " remaining!\n";
	}
	else
		std::cout << _typeName << " " << _name << " has no energy to repair!\n";
}

std::string		ClapTrap::getName( void ) const { return _name; }
unsigned int	ClapTrap::getHp( void ) const { return _hp; }
unsigned int	ClapTrap::getEp( void ) const { return _ep; }
unsigned int	ClapTrap::getDmg( void ) const { return _dmg; }
void	ClapTrap::setName( const std::string& name ) { _name = name; }
void	ClapTrap::setHp( unsigned int amount ) { _hp = amount; }
void	ClapTrap::setEp( unsigned int amount ) { _ep = amount; }
void	ClapTrap::setDmg( unsigned int amount ) {_dmg = amount; }
