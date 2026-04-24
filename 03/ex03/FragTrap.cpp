#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap( const std::string& name ) : ClapTrap(name)
{
	std::cerr << "FragTrap: Constructor called\n";
	_hp = 100;
	_ep = 100;
	_dmg = 30;
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
	std::cout << _name << " raises both pincers in the air expectantly. High fives!\n";
}
