#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
	public:

	class GradeTooHighException : public std::exception
    {
        public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
        virtual const char* what() const throw();
    };

	Form(const std::string& name = "Default", int gradeToSign = 150, int gradeToExec = 150);
	~Form();
	Form(const Form& toCopy);
	Form& operator=(const Form& op);

	std::string	getName() const;
	bool		getSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExec() const;
	void		beSigned(const Bureaucrat& b);

	private:

	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExec;
};

std::ostream&	operator<<(std::ostream& out, const Form& op);

#endif /* FORM_HPP */