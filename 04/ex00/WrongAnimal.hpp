#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <string>

class WrongAnimal {

	public:

	WrongAnimal( void );
	virtual ~WrongAnimal( void );
	WrongAnimal( const WrongAnimal& toCopy );
	WrongAnimal&	operator=( const WrongAnimal& op );

	std::string	getType( void ) const;

	void	makeSound( void ) const;

	protected:

	std::string	type;

};

#endif /* WRONGANIMAL_H */
