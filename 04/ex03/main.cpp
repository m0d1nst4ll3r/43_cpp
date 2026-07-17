#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
	std::cout << "Subject tests\n";
	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter *me = new Character("me");

		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter *bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	std::cout << "Custom tests\n";
	{
		// MateriaSource test
		MateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure()); // Full inventory test
		MateriaSource *src2 = new MateriaSource(*src); // Deep copy test
		MateriaSource *src3 = new MateriaSource();
		src3->learnMateria(new Cure());
		*src3 = *src; // Assignment test (previous Materia should be deleted, if not --> leaks)

		// Character test
		Character *me = new Character("me");
		me->equip(src->createMateria("ice"));
		me->equip(src2->createMateria("cure"));
		me->equip(src3->createMateria("cure"));
		me->equip(src2->createMateria("cure"));
		me->equip(src3->createMateria("cure")); // Full inventory test
		Character *me2 = new Character(*me); // Deep copy test
		Character *me3 = new Character();
		me3->equip(src->createMateria("cure"));
		*me3 = *me; // Assignment test (previous Materia should be deleted, if not --> leaks)

		Character *bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);
		me2->use(0, *bob);
		me2->use(1, *bob);
		me3->use(0, *bob);
		me3->use(1, *bob);

		delete bob;
		delete me;
		delete me2;
		delete me3;
		delete src;
		delete src2;
		delete src3;
	}
	return 0;
}
