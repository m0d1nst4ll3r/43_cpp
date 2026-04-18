#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <string>

class Weapon {


	public:

	Weapon( const std::string& type );

	const std::string&	getType( void ) const;
	void				setType( const std::string& type );


	private:

	std::string type;

};

#endif /* __WEAPON_H__ */
