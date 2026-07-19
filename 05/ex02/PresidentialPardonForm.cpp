#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("Presidential Pardon", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &toCopy)
	: AForm("Presidential Pardon", 25, 5), _target(toCopy._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &op)
{
	if (this != &op)
		_target = op._target;
	return *this;
}

void PresidentialPardonForm::executeInternal() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}