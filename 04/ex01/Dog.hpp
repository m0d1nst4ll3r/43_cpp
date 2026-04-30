#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal {

	public:

	Dog( void );
	virtual ~Dog( void );
	Dog( const Dog& toCopy );
	virtual Dog&	operator=( const Dog& op );

	virtual Dog*	clone( void ) const;

	virtual void	makeSound( void ) const;

	private:

	Brain	*brain;
};

#endif /* DOG_H */
