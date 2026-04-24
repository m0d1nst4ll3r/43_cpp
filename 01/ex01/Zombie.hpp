#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {


	public:

	Zombie( const std::string& name = "Default" );
	~Zombie( void );

	void	announce( void );
	void	setName( const std::string& name );

	private:

	std::string	_name;

};

#endif /* ZOMBIE_H */
