#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
	this->nickName = nickName;
}

std::string	Contact::getFirstName()
{
	return firstName;
}

std::string	Contact::getLastName()
{
	return lastName;
}

std::string	Contact::getNickName()
{
	return nickName;
}

void	Contact::display()
{
	std::cout << "\x1b[33m" << "First Name: " << "\x1b[0m" << firstName << '\n';
	std::cout << "\x1b[33m" << "Last Name: " << "\x1b[0m" << lastName << '\n';
	std::cout << "\x1b[33m" << "Nickname: " << "\x1b[0m" << nickName << '\n';
	std::cout << "\x1b[33m" << "Phone Number: " << "\x1b[0m" << phoneNumber << '\n';
	std::cout << "\x1b[33m" << "Darkest Secret: " << "\x1b[0m" << darkestSecret << '\n';
}
