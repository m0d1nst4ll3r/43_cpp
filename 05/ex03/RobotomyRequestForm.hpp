#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(const std::string& target = "Default");
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &toCopy);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &op);

private:
	virtual void executeInternal() const;

	std::string _target;
};

#endif /* ROBOTOMYREQUESTFORM_HPP */