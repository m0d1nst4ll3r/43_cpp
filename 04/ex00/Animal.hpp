#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {

	public:

	Animal( void );
	virtual ~Animal( void );

	std::string	getType( void ) const;

	virtual void	makeSound( void ) const;

	protected:

	std::string	type;

};

#endif /* ANIMAL_H */
