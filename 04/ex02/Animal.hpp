#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {

	public:

	Animal( void );
	virtual ~Animal( void );
	Animal( const Animal& toCopy );
	virtual Animal&	operator=( const Animal& op );

	std::string	getType( void ) const;

	virtual Animal*	clone( void ) const = 0;

	virtual void	makeSound( void ) const = 0;

	protected:

	std::string	type;

};

#endif /* ANIMAL_H */
