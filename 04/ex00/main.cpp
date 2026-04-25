#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <string>
#include <iostream>

int	main( void )
{

	std::cout << "Animal on stack:\n\n";

	{
		Animal	animal;
		std::cout << animal.getType() << '\n';
		animal.makeSound();
	}

	std::cout << "\nDog on stack:\n\n";

	{
		Dog		dog;
		std::cout << dog.getType() << '\n';
		dog.makeSound();
	}

	std::cout << "\nCat on stack:\n\n";

	{
		Cat		cat;
		std::cout << cat.getType() << '\n';
		cat.makeSound();
	}

	std::cout << "\nAll on heap:\n\n";

	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete i;
		delete j;
	}

	std::cout << "\nWrongcat on stack:\n\n";

	{
		WrongCat		cat;
		std::cout << cat.getType() << '\n';
		cat.makeSound();
	}

	std::cout << "\nWrongcat on heap:\n\n";

	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		meta->makeSound();
		delete meta;
		delete i;
	}
}
