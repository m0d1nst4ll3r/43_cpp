#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <string>
#include <iostream>

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

// Copy is DEEP because it makes the most sense here (no subject guidelines)
MateriaSource::MateriaSource(const MateriaSource& toCopy)
{
	for (int i = 0; i < 4; ++i)
	{
		if (toCopy._learned[i])
		{
			_learned[i] = toCopy._learned[i]->clone();
		}
		else
			_learned[i] = NULL;
	}
}

// Copy is DEEP and old Materia is deleted (no subject guidelines)
MateriaSource&	MateriaSource::operator=(const MateriaSource& op)
{
	if (this != &op)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (_learned[i])
			{
				delete _learned[i];
				_learned[i] = NULL;
			}
			if (op._learned[i])
				_learned[i] = op._learned[i]->clone();
		}
	}
	return *this;
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
		if (_learned[i] && type == _learned[i]->getType())
			return _learned[i]->clone();
	}
	return NULL;
}
