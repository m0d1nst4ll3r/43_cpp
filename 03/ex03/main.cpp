#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int	main( void )
{
	std::srand(std::time(0));

	{
		DiamondTrap	diamond("Diam");

		diamond.attack("Bill");
		diamond.takeDamage(1);
		diamond.beRepaired(1);
		diamond.guardGate();
		diamond.guardGate();
		diamond.highFivesGuys();
		diamond.whoAmI();
	}
}
