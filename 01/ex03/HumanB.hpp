#ifndef __HUMANB_H__
#define __HUMANB_H__

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

#endif /* __HUMANB_H__ */
