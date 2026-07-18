#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &toCopy)
	: AForm("Robotomy Request Form", 72, 45), _target(toCopy._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &op)
{
	if (this != &op)
		_target = op._target;
	return *this;
}

void RobotomyRequestForm::executeInternal() const
{
	std::cout << "Robotomy Request Form executed\n";
}