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
	catch (std::exception& e) { std::cerr << "Bureaucrat declaration failed: " << e.what() << ".\n"; }

	std::cout << "Attempt to declare grade 151 Bureaucrat:\n";
	try { Bureaucrat bug("Bug", 151); }
	catch (std::exception& e) { std::cerr << "Bureaucrat declaration failed: " << e.what() << ".\n"; }

	std::cout << "Attempt to demote at grade 150:\n";
	try { bob.demote(); }
	catch (std::exception& e) { std::cerr << "Demotion failed: " << e.what() << ".\n"; }

	std::cout << "Attempt to promote at grade 1:\n";
	try { john.promote(); }
	catch (std::exception& e) { std::cerr << "Promotion failed: " << e.what() << ".\n"; }

	john.demote();
	bob.promote();
}