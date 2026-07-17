#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <string>

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource();
		virtual	~MateriaSource();
		MateriaSource(const MateriaSource& toCopy);
		MateriaSource&	operator=(const MateriaSource& op);
		virtual void	learnMateria(AMateria*);
		virtual AMateria*	createMateria(std::string const & type);
	private:
		AMateria*	_learned[4];
};

#endif /* MATERIASOURCE_H */