#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

// Always init signed state to false
AForm::AForm(const AForm& toCopy)
	: _name(toCopy._name), _signed(false), _gradeToSign(toCopy._gradeToSign), _gradeToExec(toCopy._gradeToExec) {}

// Constant values so assignment makes no sense
// Signed state should always start at false
AForm& AForm::operator=(const AForm& op)
{
	(void)op;
	return *this;
}

std::ostream&	operator<<(std::ostream& out, const AForm& op)
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

std::string	AForm::getName() const { return _name; }
bool		AForm::getSigned() const { return _signed; }
int			AForm::getGradeToSign() const { return _gradeToSign; }
int			AForm::getGradeToExec() const { return _gradeToExec; }

void AForm::beSigned(const Bureaucrat &b)
{
	if (_signed)
		throw AForm::AlreadySignedException();
	if (b.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void	AForm::execute(const Bureaucrat& executor) const
{
	if (!_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > _gradeToExec)
		throw AForm::GradeTooLowException();
	try { executeInternal(); }
	catch (std::exception& e) { std::cout << e.what() << std::endl; }
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return "form is already signed";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "form is not signed";
}