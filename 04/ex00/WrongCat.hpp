#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal {

	public:

	WrongCat( void );
	virtual ~WrongCat( void );

	void	makeSound( void ) const;

};

#endif /* WRONGCAT_H */
