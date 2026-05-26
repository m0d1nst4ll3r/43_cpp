#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <string>
#include <iostream>

int	main( void )
{
	std::cout << "Subject tests:\n\n";

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

	std::cout << "\nWrongCat as WrongCat:\n\n";

	{
		WrongCat		cat;
		std::cout << cat.getType() << '\n';
		cat.makeSound();
	}

	std::cout << "\nWrongCat as Animal:\n\n";

	{
		const WrongCat i;
		const WrongAnimal *meta = &i;
		std::cout << meta->getType() << " " << std::endl;
		meta->makeSound();
	}
}
