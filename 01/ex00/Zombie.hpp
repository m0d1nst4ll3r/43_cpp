#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {


	public:

	Zombie( const std::string& name );
	~Zombie( void );

	void	announce( void );

	private:

	std::string	_name;

};

#endif /* ZOMBIE_H */
