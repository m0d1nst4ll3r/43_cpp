#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(const std::string &firstName, const std::string &lastName, const std::string &nickName, const std::string &phoneNumber, const std::string &darkestSecret)
	: firstName(firstName), lastName(lastName), nickName(nickName), phoneNumber(phoneNumber), darkestSecret(darkestSecret) {}

const std::string	&Contact::getFirstName() const
{
	return firstName;
}

const std::string	&Contact::getLastName() const
{
	return lastName;
}

const std::string	&Contact::getNickName() const
{
	return nickName;
}

void	Contact::display() const
{
	std::cout << "\x1b[33m" << "First Name: " << "\x1b[0m" << firstName << '\n';
	std::cout << "\x1b[33m" << "Last Name: " << "\x1b[0m" << lastName << '\n';
	std::cout << "\x1b[33m" << "Nickname: " << "\x1b[0m" << nickName << '\n';
	std::cout << "\x1b[33m" << "Phone Number: " << "\x1b[0m" << phoneNumber << '\n';
	std::cout << "\x1b[33m" << "Darkest Secret: " << "\x1b[0m" << darkestSecret << '\n';
}
