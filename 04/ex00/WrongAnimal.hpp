#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <string>

class WrongAnimal {

	public:

	WrongAnimal( void );
	virtual ~WrongAnimal( void );

	std::string	getType( void ) const;

	void	makeSound( void ) const;

	protected:

	std::string	type;

};

#endif /* WRONGANIMAL_H */
