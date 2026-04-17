#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <string>

class Zombie {


	public:

	Zombie( const std::string& name );
	~Zombie( void );

	void	announce( void );

	private:

	std::string	_name;

};

#endif
