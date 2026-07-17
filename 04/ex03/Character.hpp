#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Character : public ICharacter {
	public:
		Character(const std::string& name = "Default");
		virtual	~Character();
		Character(Character& toCopy);
		Character&	operator=(Character& op);
		virtual const std::string& getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
	private:
		std::string	_name;
		AMateria*	_inv[4];
};

#endif /* CHARACTER_H */