#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include <string>

class Dog : public Animal {

	public:

	Dog( void );
	virtual ~Dog( void );

	virtual void	makeSound( void ) const;

};

#endif /* DOG_H */
