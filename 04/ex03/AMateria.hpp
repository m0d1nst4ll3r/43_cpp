#ifndef AMATERIA_H
#define AMATERIA_H

class AMateria {

	public:


	AMateria(std::string const & type);

	const std::string&	getType() const; //Returns the materia type

	virtual AMateria*	clone() const = 0;

	virtual void		use(ICharacter& target);

	protected:

	std::string	_type;

	private:


};

AMateria::use(ICharacter& target)
{
	std::cout << target.getName() << 
}

class Ice : public AMateria {

	public:

	Ice();

	virtual Ice*	clone() const;
};

Ice::Ice() : _type("ice") {}
Ice*	Ice::clone() const {return new Ice(*this);}

class Cure : public AMateria {

	public:

	Cure();

	virtual Cure*	clone() const;
	
	virtual void	use(ICharacter& target);
};

Cure::Cure() : _type("cure")
{
}
Cure*	Cure::clone() const {return new Cure(*this);}

virtual void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n"
}

#endif /* AMATERIA_H */
