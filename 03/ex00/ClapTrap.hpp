#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap {


	public:

	ClapTrap( void );
	ClapTrap( const std::string& name );
	ClapTrap( const ClapTrap& toCopy );
	~ClapTrap( void );

	ClapTrap&	operator=( const ClapTrap& op );

	void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );

	private:

	std::string	_name;
	unsigned int		_hp;
	unsigned int		_ep;
	unsigned int		_dmg;

};

#endif /* CLAPTRAP_H */
