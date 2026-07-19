#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

int	main()
{
	Bureaucrat	bob("Bob", 145);
	Bureaucrat	hermes("Hermes Conrad", 70);
	Bureaucrat	john("John", 5);
	Bureaucrat	dflBur;
	ShrubberyCreationForm	scf("home");
	RobotomyRequestForm		rrf("Bender");
	PresidentialPardonForm	ppf("Nobody");

	std::cout << "Bureaucrats:\n\t" << bob << "\n\t" << hermes << "\n\t" << john << "\n\t" << dflBur << "\n\n";
	std::cout << "Forms:\n\t" << scf << "\n\t" << rrf << "\n\t" << ppf << "\n\n";

	bob.signForm(ppf);
	bob.signForm(scf);
	hermes.signForm(rrf);
	john.signForm(ppf);

	std::cout << "\n" << ppf << "\n\n";

	bob.executeForm(scf);
	hermes.executeForm(scf);
	hermes.executeForm(scf);
	hermes.executeForm(rrf);
	john.executeForm(rrf);
	john.executeForm(ppf);
}
