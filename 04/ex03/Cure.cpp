#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {}
Cure::~Cure() {}
Cure::Cure(const Cure& toCopy) : AMateria(toCopy) {}

Cure&	Cure::operator=(const Cure& op)
{
	(void)op;
	return *this;
}

Cure*	Cure::clone() const
{
    return new Cure(*this);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
