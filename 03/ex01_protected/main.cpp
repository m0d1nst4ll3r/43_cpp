#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int	main( void )
{
	std::srand(std::time(0));

	{
		ClapTrap	joe("Joe");

		joe.attack("Bill");
		joe.takeDamage(4);
		joe.takeDamage(4);
		joe.takeDamage(4);
		joe.takeDamage(4);
		for (int i = 0; i < 10; ++i)
			joe.beRepaired(1);
	}

	std::cout << '\n';

	ScavTrap	scavy("Scavy");

	scavy.attack("Target Dummy");
	scavy.takeDamage(5);
	scavy.takeDamage(50);
	scavy.takeDamage(50);
	scavy.beRepaired(150);
	scavy.guardGate();

	ScavTrap	henryScavill;
	henryScavill = scavy;
	henryScavill.takeDamage(100);
	henryScavill.guardGate();
}
