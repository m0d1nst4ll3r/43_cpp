#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

	public:

	FragTrap( const std::string& name = "Default" );
	FragTrap( const FragTrap& toCopy );
	virtual ~FragTrap( void );

	FragTrap&	operator=( const FragTrap& op );

	void	highFivesGuys( void );

};

#endif /* FRAGTRAP_H */
