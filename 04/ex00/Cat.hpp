#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include <string>

class Cat : public Animal {

	public:

	Cat( void );
	virtual ~Cat( void );

	virtual void	makeSound( void ) const;

};

#endif /* CAT_H */
