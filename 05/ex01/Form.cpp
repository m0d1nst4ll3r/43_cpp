#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>

Form::Form(const std::string &name, int gradeToSign, int gradeToExec)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
}

Form::~Form() {}

// Always init signed state to false
Form::Form(const Form &toCopy)
	: _name(toCopy._name), _signed(false), _gradeToSign(toCopy._gradeToSign), _gradeToExec(toCopy._gradeToExec) {}

// Constant values so assignment makes no sense
// Signed state should always start at false
Form &Form::operator=(const Form &op)
{
	(void)op;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Form &op)
{
	if (op.getSigned())
	{
		out << op.getName() << ", signed, needs grade "
			<< op.getGradeToExec() << " to execute.";
	}
	else
	{
		out << op.getName() << ", not signed, needs grade "
			<< op.getGradeToSign() << " to sign and grade "
			<< op.getGradeToExec() << " to execute.";
	}
	return out;
}

std::string Form::getName() const { return _name; }
bool Form::getSigned() const { return _signed; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExec() const { return _gradeToExec; }

void Form::beSigned(const Bureaucrat &b)
{
	if (_signed)
		throw Form::AlreadySignedException();
	if (b.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

const char *Form::AlreadySignedException::what() const throw()
{
	return "form is already signed";
}