#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include <string>

class AMateria {

	public:

	AMateria(std::string const& type);

	const std::string&	getType() const; //Returns the materia type

	virtual AMateria*	clone() const = 0;

	virtual void		use(ICharacter& target);


	protected:

		std::string	_type;


	private:


};

AMateria::AMateria(std::string const& type) : _type(type) {}

// What is this for? Why not = 0?
// This is a virtual function that will be overriden by inherited classes..?
AMateria::use(ICharacter& target)
{
	(void)target;
}

class Ice : public AMateria {

	public:

	Ice();

	virtual Ice*	clone() const;

	virtual void	use(ICharacter& target);
};

Ice::Ice() : AMateria("ice") {}
Ice*	Ice::clone() const {return new Ice(*this);}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "\n";
}

class Cure : public AMateria {

	public:

	Cure();

	virtual Cure*	clone() const;

	virtual void	use(ICharacter& target);
};

Cure::Cure() : AMateria("cure") {}
Cure*	Cure::clone() const {return new Cure(*this);}

virtual void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

#endif /* AMATERIA_H */
