#ifndef HARL_H
#define HARL_H

#include <string>

class Harl {


	public:

	Harl( void );

	void	complain( std::string level );


	private:

	std::string	level[4];
	void 		(Harl::*action[4])( void );

	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );

};

#endif /* HARL_H */
