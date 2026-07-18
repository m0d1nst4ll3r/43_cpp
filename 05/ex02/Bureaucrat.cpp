#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>
#include <iostream>

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &toCopy)
	: _name(toCopy._name), _grade(toCopy._grade)
{
}

// Cannot copy name
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &op)
{
	if (this != &op)
		_grade = op._grade;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &op)
{
	out << op.getName() << ", bureaucrat grade " << op.getGrade() << ".";
	return out;
}

std::string Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::promote()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::demote()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << ".\n";
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << ": " << e.what() << ".\n";
	}
}

void Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << ".\n";
	}
	catch (const std::exception &e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << ": " << e.what() << ".\n";
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat: grade is too high (must be 1 or higher)";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat: grade is too low (must be 150 or lower)";
}
