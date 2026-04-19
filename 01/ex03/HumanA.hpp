#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"
#include <string>

class HumanA {


	public:

	HumanA( const std::string& name, Weapon& weapon );

	void	attack( void );


	private:

	std::string	name;
	Weapon&		weapon;

};

#endif /* HUMANA_H */
