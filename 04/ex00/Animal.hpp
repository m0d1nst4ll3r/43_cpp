#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {

	public:

	Animal( void );
	virtual ~Animal( void );
	Animal( const Animal& toCopy );
	Animal&	operator=( const Animal& op );

	std::string	getType( void ) const;

	virtual void	makeSound( void ) const;

	protected:

	std::string	type;

};

#endif /* ANIMAL_H */
