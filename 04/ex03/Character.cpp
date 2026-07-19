#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>
#include <iostream>

// Init all Materia slots to 0 (empty)
Character::Character(const std::string& name) : _name(name)
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
Character::Character(const Character& toCopy)
	: _name(toCopy._name)
{
	for (int i = 0; i < 4; ++i)
	{
		if (toCopy._inv[i])
			_inv[i] = toCopy._inv[i]->clone();
		else
			_inv[i] = NULL;
	}
}

// Copy is DEEP and old Materias are deleted before replacing
Character&	Character::operator=(const Character& op)
{
	if (this != &op)
	{
		_name = op._name;
		for (int i = 0; i < 4; ++i)
		{
			if (_inv[i])
			{
				delete _inv[i];
				unequip(i);
			}
			if (op._inv[i])
				_inv[i] = op._inv[i]->clone();
		}
	}
	return *this;
}

const std::string& Character::getName() const
{
	return _name;
}

// Decided to delete m if the inventory is full since we are not returning any success/failure
// Subject provides no guidelines
void	Character::equip(AMateria* m)
{
	int	i;
	for (i = 0; i < 4; ++i)
	{
		if (!_inv[i])
		{
			_inv[i] = m;
			return ;
		}
	}
	std::cout << _name << "'s inventory is full (4 max)\n";
	delete m;
}

// Not deleting Materia when unequipping as per subject guidelines
void	Character::unequip(int idx)
{
	_inv[idx] = NULL;
}

// Unclear if Materias should be single-use or not (deleted when used), subject provides no guideline
// I decided that they should, as it makes the most sense
void	Character::use(int idx, ICharacter& target)
{
	if (_inv[idx])
	{
		_inv[idx]->use(target);
		delete _inv[idx];
		unequip(idx);
	}
}
