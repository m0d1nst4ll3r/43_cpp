#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &toCopy)
	: AForm("Shrubbery Creation Form", 145, 137), _target(toCopy._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &op)
{
	if (this != &op)
		_target = op._target;
	return *this;
}

void ShrubberyCreationForm::executeInternal() const
{
	std::cout << "Shrubbery Creation Form executed\n";
}