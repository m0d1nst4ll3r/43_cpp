#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap {

	public:

	DiamondTrap( const std::string& name = "Default" );
	DiamondTrap( const DiamondTrap& toCopy );
	virtual ~DiamondTrap( void );

	DiamondTrap&	operator=( const DiamondTrap& op );

	void	whoAmI( void );

	private:

	std::string	_name;

};

#endif /* DIAMONDTRAP_H */
