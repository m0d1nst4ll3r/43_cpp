#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern
{
	public:
	Intern();
	~Intern();
	Intern(const Intern& toCopy);
	const Intern&	operator=(const Intern& op);

	AForm*	makeForm(const std::string& form, const std::string& target);
};

#endif /* INTERN_HPP */