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
		joe.takeDamage(0);
		joe.takeDamage(4);
		joe.takeDamage(4);
		joe.takeDamage(4);
		joe.takeDamage(4);
		for (int i = 0; i < 10; ++i)
			joe.beRepaired(1);
	}

	std::cout << '\n';

	{
		ScavTrap	scavill("Henry Scavill");

		scavill.attack("Target Dummy");
		scavill.takeDamage(5);
		scavill.takeDamage(50);
		scavill.takeDamage(50);
		scavill.beRepaired(150);
		scavill.guardGate();

		ScavTrap	scavy;
		scavy = scavill;
		scavy.takeDamage(100);
		scavy.guardGate();
	}

	std::cout << '\n';

	{
		FragTrap	fraggy("Fraggy");

		fraggy.attack("Handsome Jack");
		fraggy.takeDamage(200);

		FragTrap	froggy;
		froggy = fraggy;
		froggy.beRepaired(1);
		froggy.highFivesGuys();
	}
}
