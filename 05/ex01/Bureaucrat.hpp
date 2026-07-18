#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
#include <string>
#include <iostream>

class Form;

class Bureaucrat
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

    Bureaucrat(const std::string& name = "Default", int grade = 150);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& toCopy);
    Bureaucrat& operator=(const Bureaucrat& op);

    std::string getName() const;
    int         getGrade() const;
    void        promote();
    void        demote();
    void        signForm(Form& form) const;

    private:

    const std::string   _name;
    int                 _grade;
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& op);

#endif /* BUREAUCRAT_HPP */