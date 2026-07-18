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
	ShrubberyCreationForm	scForm("Home");
	RobotomyRequestForm		rrForm("Bender");
	PresidentialPardonForm	ppForm("Nobody");

	std::cout << "Bureaucrats:\n\t" << bob << "\n\t" << hermes << "\n\t" << john << "\n\t" << dflBur << "\n\n";
	std::cout << "Forms:\n\t" << scForm << "\n\t" << rrForm << "\n\t" << ppForm << "\n\n";

	bob.signForm(ppForm);
	bob.signForm(scForm);
	hermes.signForm(rrForm);
	john.signForm(ppForm);

	std::cout << "\n" << ppForm << "\n\n";

	bob.executeForm(scForm);
	hermes.executeForm(scForm);
	hermes.executeForm(scForm);
	hermes.executeForm(rrForm);
	john.executeForm(rrForm);
	john.executeForm(ppForm);
}
