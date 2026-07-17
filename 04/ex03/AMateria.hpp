#ifndef AMATERIA_H
#define AMATERIA_H

#include "ICharacter.hpp"
#include <string>

class ICharacter;

class AMateria {
	public:
		AMateria(std::string const& type);
		virtual ~AMateria();
		AMateria(const AMateria& toCopy);
		AMateria&	operator=(const AMateria& op);
		const std::string&	getType() const; //Returns the materia type
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
	protected:
		const std::string	_type;
};

#endif /* AMATERIA_H */