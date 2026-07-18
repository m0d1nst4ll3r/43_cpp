#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
public:
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class AlreadySignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	AForm(const std::string &name = "Default", int gradeToSign = 150, int gradeToExec = 150);
	~AForm();
	AForm(const AForm &toCopy);
	AForm &operator=(const AForm &op);

	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	void beSigned(const Bureaucrat &b);
	void execute(const Bureaucrat &executor) const;

private:
	virtual void executeInternal() const = 0;

	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExec;
};

std::ostream &operator<<(std::ostream &out, const AForm &op);

#endif /* AFORM_HPP */
