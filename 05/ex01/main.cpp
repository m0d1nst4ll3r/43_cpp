#include "Bureaucrat.hpp"
#include <iostream>

int	main()
{
	Bureaucrat	bob("Bob", 150);
	Bureaucrat	john("John", 1);
	Bureaucrat	dfl;

	std::cout << bob << " " << john << " " << dfl << std::endl;

	std::cout << "Attempt to declare grade 0 Bureaucrat:\n";
	try { Bureaucrat bug("Bug", 0); }
	catch (std::exception& e) { std::cout << e.what() << std::endl; }

	std::cout << "Attempt to declare grade 151 Bureaucrat:\n";
	try { Bureaucrat bug("Bug", 151); }
	catch (std::exception& e) { std::cout << e.what() << std::endl; }

	std::cout << "Attempt to demote at grade 150:\n";
	try { bob.demote(); }
	catch (std::exception& e) { std::cout << e.what() << std::endl; }

	std::cout << "Attempt to promote at grade 1:\n";
	try { john.promote(); }
	catch (std::exception& e) { std::cout << e.what() << std::endl; }

	john.demote();
	bob.promote();
}