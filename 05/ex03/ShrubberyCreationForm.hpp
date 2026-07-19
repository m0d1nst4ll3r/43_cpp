#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(const std::string& target = "Default");
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &toCopy);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &op);

private:
	virtual void executeInternal() const;

	std::string _target;
};

#endif /* SHRUBBERYCREATIONFORM_HPP */