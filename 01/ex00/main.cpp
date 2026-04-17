#include "Zombie.hpp"

Zombie*	newZombie( std::string name );
void	randomChump( std::string name);

int	main()
{
	Zombie *bob = newZombie("Bob");
	bob->announce();
	randomChump("Brian");
	bob->announce();
	randomChump("Tom");
	bob->announce();
	delete bob;
}
