#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>
#include <iostream>

// Init all Materia slots to 0 (empty)
Character::Character(std::string& name) : _name(name)
{
	for (int i = 0; i < 4; ++i)
		_inv[i] = NULL;
}

// Also delete all Materias in inventory
Character::~Character()
{
	for (int i = 0; i < 4; ++i)
	{
		if (_inv[i])
			delete _inv[i];
	}
}

// As per subject guidelines, copy is DEEP (allocates new Materia instead of copying address)
// And original Materia is unequipped and deleted
Character::Character(Character& toCopy)
	: _name(toCopy._name)
{
	for (int i = 0; i < 4; ++i)
	{
		if (toCopy._inv[i])
		{
			_inv[i] = toCopy._inv[i].clone();
			delete toCopy._inv[i];
			toCopy.unequip(i);
		}
		else
			_inv[i] = NULL;
	}
}

Character&	Character::operator=(Character& op)
{
	if (this != &op)
	{
		_name = op._name;
		for (int i = 0; i < 4; ++i)
		{
			if (op._inv[i])
			{
				_inv[i] = op._inv[i]->clone();
				delete op._inv[i];
				op.unequip(i);
			}
			else
				_inv[i] = NULL;
		}
	}
	return *this;
}

const std::string& Character::getName() const
{
	return _name;
}

void	Character::equip(AMateria* m)
{
	int	i;
	for (i = 0; i < 4 && !_inv[i]; ++i)
		i++;
	if (i < 4)
		_inv[i] = m;
	else
	{
		std::cout << _name << "'s inventory is full (4 max).\n";
		delete m;
	}
}

// Not deleting Materia when unequipping as per subject guidelines
void	Character::unequip(int idx)
{
	_inv[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (_inv[idx])
	{
		_inv[idx]->use(target);
		delete _inv[idx];
		unequip(idx);
	}
}
