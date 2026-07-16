#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	joe("Joe");

	joe.attack("Bill");
	joe.takeDamage(0);
	joe.takeDamage(1);
	joe.takeDamage(4);
	joe.takeDamage(4);
	for (int i = 0; i < 10; ++i)
		joe.beRepaired(1);
	joe.attack("Bill");
	joe.takeDamage(1000000);
	joe.takeDamage(0);
	joe.beRepaired(1);
	joe.attack("Bill");
}
