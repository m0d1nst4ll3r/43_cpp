#ifndef CONTACT
# define CONTACT
# include <iostream>

class Contact
{
	// Private by default
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
	public:
	Contact()
	{
		// Used when declaring contactList[8]
		// Not strictly necessary to initialize strings
		firstName = "";
		lastName = "";
		nickName = "";
		phoneNumber = "";
		darkestSecret = "";
	};
	Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
	{
		// Used when creating a new contact
		this->firstName = firstName;
		this->lastName = lastName;
		this->phoneNumber = phoneNumber;
		this->darkestSecret = darkestSecret;
		this->nickName = nickName;
	};
	std::string	getFirstName()
	{
		return firstName;
	};
	std::string	getLastName()
	{
		return lastName;
	};
	std::string	getNickName()
	{
		return nickName;
	};
	void	display();
};

void	Contact::display()
{
	std::cout << "\x1b[33m" << "First Name: " << "\x1b[0m" << firstName << '\n';
	std::cout << "\x1b[33m" << "Last Name: " << "\x1b[0m" << lastName << '\n';
	std::cout << "\x1b[33m" << "Nickname: " << "\x1b[0m" << nickName << '\n';
	std::cout << "\x1b[33m" << "Phone Number: " << "\x1b[0m" << phoneNumber << '\n';
	std::cout << "\x1b[33m" << "Darkest Secret: " << "\x1b[0m" << darkestSecret << '\n';
}

#endif
