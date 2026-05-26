#ifndef CHARACTER_H
#define CHARACTER_H

class Character : public ICharacter {
	public:
		Character(std::string& name = "Default");
		virtual	~Character();
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
	
	private:
		std::string	_name;
		AMateria*	_inv[4];
}

Character::Character(std::string& name) : _name(name) {}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
		_inv[i] = NULL;
}

// Delete m if we can't insert it, or what? Is this our responsibility?
Character::equip(AMateria* m)
{
	for (int i = 0; inventory[i]; ++i)
		i++;
	if (i < 4)
		inventory[i] = m;
}

// Delete when we unequip? Subject says NO.
// Wtf does "Handle the Materias your character leaves on the floor as you like." mean?
Character::unequip(int idx)
{
	inventory[idx] = NULL;
}

// Delete when we use?!
Character::use(int idx, ICharacter& target)
{
	if (inventory[idx])
	{
		inventory[idx].use(target);
		unequip(idx);
	}
}

#endif /* CHARACTER_H */
