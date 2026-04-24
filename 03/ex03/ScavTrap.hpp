#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

	public:

	ScavTrap( const std::string& name = "Default" );
	ScavTrap( const ScavTrap& toCopy );
	virtual ~ScavTrap( void );

	ScavTrap&	operator=( const ScavTrap& op );

	void	attack( const std::string& target );
	void	guardGate( void );

	private:

	bool	_guarding;

};

#endif /* SCAVTRAP_H */
