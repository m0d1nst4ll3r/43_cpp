#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"
#include <string>

class HumanB {


	public:

	HumanB( const std::string& name );

	void	setWeapon( Weapon& weapon );

	void	attack( void );


	private:

	std::string	name;
	Weapon*		weapon;

};

#endif /* HUMANB_H */
