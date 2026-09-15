#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>

namespace
{
	AForm *createPresidentialPardon(const std::string &target)
	{
		return new PresidentialPardonForm(target);
	}

	AForm *createRobotomyRequest(const std::string &target)
	{
		return new RobotomyRequestForm(target);
	}

	AForm *createShrubberyCreation(const std::string &target)
	{
		return new ShrubberyCreationForm(target);
	}
}

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern &toCopy) { (void)toCopy; }

const Intern &Intern::operator=(const Intern &op)
{
	(void)op;
	return *this;
}

AForm *Intern::makeForm(const std::string &form, const std::string &target)
{
	static std::string	forms[] = {"Presidential Pardon", "Robotomy Request", "Shrubbery Creation"};
	static AForm		*(*createForm[])(const std::string&) = {&createPresidentialPardon, &createRobotomyRequest, &createShrubberyCreation};
	static int			numForms = sizeof(forms) / sizeof(*forms);
	for (int i = 0; i < numForms;++i)
	{
		if (form == forms[i])
		{
			std::cout << "Intern creates " << form << ".\n";
			return createForm[i](target);
		}
	}
	std::cout << "Form '" << form << "' doesn't exist.\n";
	return NULL;
}