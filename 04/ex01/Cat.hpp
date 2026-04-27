#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal {

	public:

	Cat( void );
	virtual ~Cat( void );
	Cat( const Cat& toCopy );
	virtual Cat&	operator=( const Cat& op );

	virtual void	makeSound( void ) const;

	private:

	Brain	*brain;
};

#endif /* CAT_H */
