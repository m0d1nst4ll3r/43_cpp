#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap {


	public:

	ClapTrap( const std::string& name = "Default" );
	ClapTrap( const ClapTrap& toCopy );
	virtual ~ClapTrap( void );

	ClapTrap&	operator=( const ClapTrap& op );

	void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );

	protected:

	std::string			_name;
	unsigned int		_hp;
	unsigned int		_ep;
	unsigned int		_dmg;

};

#endif /* CLAPTRAP_H */
