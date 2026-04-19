#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {


	public:

	Weapon( const std::string& type );

	const std::string&	getType( void ) const;
	void				setType( const std::string& type );


	private:

	std::string type;

};

#endif /* WEAPON_H */
