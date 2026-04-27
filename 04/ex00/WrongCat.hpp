#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal {

	public:

	WrongCat( void );
	virtual ~WrongCat( void );
	WrongCat( const WrongCat& toCopy );
	WrongCat&	operator=( const WrongCat& op );

	void	makeSound( void ) const;

};

#endif /* WRONGCAT_H */
