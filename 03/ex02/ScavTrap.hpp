#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	public:

	ScavTrap( void );
	ScavTrap( const std::string& name );
	ScavTrap( const ScavTrap& toCopy );
	virtual ~ScavTrap( void );

	ScavTrap&	operator=( const ScavTrap& op );

	void	guardGate( void );

	private:

	bool	_guarding;

};

#endif /* SCAVTRAP_H */
