#ifndef __HUMANA_H__
#define __HUMANA_H__

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

#endif /* __HUMANA_H__ */
