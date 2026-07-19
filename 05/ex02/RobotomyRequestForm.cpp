#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <ctime>

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
	static bool	seeded = false;
	if (!seeded)
	{ // Combining tv_usec and std::clock for more randomness (this is overkill)
		struct timeval	tv;
		gettimeofday(&tv, NULL);
		srand(static_cast<unsigned int>(tv.tv_usec) ^ static_cast<unsigned int>(std::clock()));
		seeded = true;
	}
	std::cout << "* loud drilling noises *\n";
	if (rand() % 2)
		std::cout << _target << " has been robotomized.\n";
	else
		std::cout << "Robotomy has failed.\n";
}