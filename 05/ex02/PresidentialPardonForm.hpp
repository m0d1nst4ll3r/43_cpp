#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(const std::string& target = "Default");
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &toCopy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &op);

private:
	virtual void executeInternal() const;

	std::string _target;
};

#endif /* PRESIDENTIALPARDONFORM_HPP */