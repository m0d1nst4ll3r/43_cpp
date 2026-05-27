#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <string>

// Init all learned Materia slots to 0 (empty)
MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		_learned[i] = NULL;
}

// Also delete all learned Materias
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (_learned[i])
			delete _learned[i];
	}
}

// If full, prints message and deletes Materia
void	MateriaSource::learnMateria(AMateria* toLearn)
{
	for (int i = 0; i < 4; ++i)
	{
		if (!_learned[i])
		{
			_learned[i] = toLearn;
			return ;
		}
	}
	std::cout << "No more Materias can be learned (4 max)\n";
	delete toLearn;
}

// Returns 0 if type is unknown
AMateria*	MateriaSource::createMateria(const std::string& type)
{
	// Search through learned templates
	for (int i = 0; i < 4; ++i)
	{
		if (_learned[i] && type == *_learned[i])
			return _learned[i].clone();
	}
	return NULL;
}
