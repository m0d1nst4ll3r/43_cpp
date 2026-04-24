#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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

	{
		ScavTrap	scavy("Scavy");

		scavy.attack("Target Dummy");
		scavy.takeDamage(5);
		scavy.takeDamage(50);
		scavy.takeDamage(50);
		scavy.beRepaired(150);
		scavy.guardGate();

		ScavTrap	henryScavill;
		henryScavill = scavy;
		henryScavill.setName("Scavill");
		henryScavill.takeDamage(100);
		henryScavill.guardGate();
	}

	std::cout << '\n';

	{
		FragTrap	fraggy("Fraggy");

		fraggy.attack("Handsome Jack");
		fraggy.takeDamage(200);

		FragTrap	froggy = fraggy;
		froggy.setName("Froggy");
		froggy.beRepaired(1);
		froggy.highFivesGuys();
	}
}
