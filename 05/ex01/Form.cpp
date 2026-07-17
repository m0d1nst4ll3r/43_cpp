Form::Form(const std::string& name = "Default", bool signedVal = false, int gradeToSign = 150, int gradeToExec = 150)
	: _name(name), _signed(signedVal), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {}
Form::~Form() {}
Form::Form(const Form& toCopy)
	: _name(toCopy._name), _signed(toCopy._signed), _gradeToSign(toCopy._gradeToSign), _gradeToExec(toCopy._gradeToExec) {}

// Cannot only change _signed value
Form& Form::operator=(const Form& op)
{
	if (this != &op)
		_signed = op._signed;
	return *this;
}

std::string	getName() const { return _name; }
bool		getSigned() const { return _signed; }
int			getGradeToSign() const { return _gradeToSign; }
int			getGradeToExec() const { return _gradeToExec; }

void	Form::beSigned(const Bureaucrat& b)
{
	if (_signed)
		std::cout << "Grade " << _name << " is already signed.\n";
	else if (b.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form: grade is too high (must be 1 or higher)";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form: grade is too low (must be 150 or lower)";
}