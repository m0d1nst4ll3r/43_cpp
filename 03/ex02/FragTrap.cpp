#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap( void ) : ClapTrap("Default", "FragTrap")
{
	std::cerr << "FragTrap: Default constructor called\n";
	this->setHp(100);
	this->setEp(100);
	this->setDmg(30);
}

FragTrap::FragTrap( const std::string& name ) : ClapTrap(name, "FragTrap")
{
	std::cerr << "FragTrap: Name constructor called\n";
	this->setHp(100);
	this->setEp(100);
	this->setDmg(30);
}

FragTrap::FragTrap( const FragTrap& toCopy ) : ClapTrap(toCopy)
{
	std::cerr << "FragTrap: Copy constructor called\n";
}

FragTrap::~FragTrap( void ) { std::cerr << "FragTrap: Destructor called\n"; }

FragTrap&	FragTrap::operator=( const FragTrap& op )
{
	std::cerr << "FragTrap: Copy assignment operator overload called\n";
	if (this != &op)
		ClapTrap::operator=(op);
	return *this;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << this->getName() << " raises both pincers in the air expectantly. High fives!\n";
}
