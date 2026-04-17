#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

int	main( void )
{
	const int	N = 4;
	Zombie*		horde = zombieHorde(N, "Bob");
	for (int i = 0; i < N; ++i)
		horde[i].announce();
	delete[] horde;
}
