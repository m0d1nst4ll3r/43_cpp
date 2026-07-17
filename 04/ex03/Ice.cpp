#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {}
Ice::~Ice() {}
Ice::Ice(const Ice& toCopy) : AMateria(toCopy) {}

Ice&	Ice::operator=(const Ice& op)
{
	(void)op;
	return *this;
}

Ice*	Ice::clone() const
{
    return new Ice(*this);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
