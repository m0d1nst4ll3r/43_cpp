#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <iostream>

int	main()
{
	Intern		someRandomIntern;
	Bureaucrat	bob("Bob", 145);
	Bureaucrat	hermes("Hermes Conrad", 70);
	Bureaucrat	john("John", 5);
	Bureaucrat	dflBur;
	AForm		*scf;
	AForm		*rrf;
	AForm		*ppf;

	std::cout << "Bureaucrats:\n\t" << bob << "\n\t" << hermes << "\n\t" << john << "\n\t" << dflBur << "\n\n";

	std::cout << "Creating forms:\n";
	scf = someRandomIntern.makeForm("DoesntExist", "target");
	scf = someRandomIntern.makeForm("Shrubbery Creation", "home");
	rrf = someRandomIntern.makeForm("Robotomy Request", "Bender");
	ppf = someRandomIntern.makeForm("Presidential Pardon", "Nobody");
	std::cout << "\n";

	std::cout << "Forms:\n\t" << *scf << "\n\t" << *rrf << "\n\t" << *ppf << "\n\n";

	bob.signForm(*ppf);
	bob.signForm(*scf);
	hermes.signForm(*rrf);
	john.signForm(*ppf);

	std::cout << "\n" << *ppf << "\n\n";

	bob.executeForm(*scf);
	hermes.executeForm(*scf);
	hermes.executeForm(*scf);
	hermes.executeForm(*rrf);
	john.executeForm(*rrf);
	john.executeForm(*ppf);

	delete rrf;
	delete ppf;
	delete scf;
}
