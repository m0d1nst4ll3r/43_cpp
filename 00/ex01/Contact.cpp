#include "Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact() {}

Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& nickName, const std::string& phoneNumber, const std::string& darkestSecret)
	: _firstName(firstName), _lastName(lastName), _nickName(nickName), _phoneNumber(phoneNumber), _darkestSecret(darkestSecret) {}

const std::string&	Contact::getFirstName() const
{
	return _firstName;
}

const std::string&	Contact::getLastName() const
{
	return _lastName;
}

const std::string&	Contact::getNickName() const
{
	return _nickName;
}

void	Contact::display() const
{
	std::cout << "\x1b[33m" << "First Name: " << "\x1b[0m" << _firstName << '\n';
	std::cout << "\x1b[33m" << "Last Name: " << "\x1b[0m" << _lastName << '\n';
	std::cout << "\x1b[33m" << "Nickname: " << "\x1b[0m" << _nickName << '\n';
	std::cout << "\x1b[33m" << "Phone Number: " << "\x1b[0m" << _phoneNumber << '\n';
	std::cout << "\x1b[33m" << "Darkest Secret: " << "\x1b[0m" << _darkestSecret << '\n';
}
