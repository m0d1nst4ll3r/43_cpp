#include "Harl.hpp"
#include <iostream>

namespace
{
	void	complainWrapper( const std::string& level, Harl& harl )
	{
		std::cout << "[ " << level << " ]\n";
		harl.complain(level);
		std::cout << '\n';
	}

	void	filter( const std::string& level)
	{
		std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		Harl		harl;
		int			i = 0;

		while (i < 4 && levels[i] != level)
			i++;
		switch (i)
		{
			case 0:
				complainWrapper(levels[0], harl);
				complainWrapper(levels[1], harl);
				complainWrapper(levels[2], harl);
				complainWrapper(levels[3], harl);
				break ;
			case 1:
				complainWrapper(levels[1], harl);
				complainWrapper(levels[2], harl);
				complainWrapper(levels[3], harl);
				break ;
			case 2:
				complainWrapper(levels[2], harl);
				complainWrapper(levels[3], harl);
				break ;
			case 3:
				complainWrapper(levels[3], harl);
				break ;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]\n";
		}
	}
}

int	main(int ac, char **av)
{
	if ( ac != 2)
		filter("");
	else
		filter(std::string(av[1]));
}
