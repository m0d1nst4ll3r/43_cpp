#ifndef __HARL_H__
#define __HARL_H__

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

#endif /* __HARL_H__ */
