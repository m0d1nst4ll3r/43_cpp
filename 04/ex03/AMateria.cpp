#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

AMateria::AMateria(std::string const& type) : _type(type) {}

AMateria::~AMateria() {}

// Copy/assign do nothing, make no sense here, but we are forced to have orthodox canonical form
// ¯\_(ツ)_/¯
AMateria(const AMateria& toCopy)
{
	(void)toCopy;
}

AMateria&	operator=(const AMateria& op)
{
	(void)op;
	return *this;
}

const std::string&	AMateria::getType() const
{
	return _type;
}

// Unclear what this function's use is
// It is virtual meaning it's intended to be replaced by children, so no if (_type == "ice") situation
// But it's not pure virtual (= 0) meaning it's supposed to be defined
// No guidelines in subject, therefore we do nothing ¯\_(ツ)_/¯
AMateria::use(ICharacter& target)
{
	(void)target;
}
