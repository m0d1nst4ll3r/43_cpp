#ifndef CONTACT
# define CONTACT
# include <iostream>
# include <string>

class Contact
{
	// Private data members
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

	// Public methods
	public:
	// Empty constructor
	Contact();
	// Args constructor
	Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);

	// Getters
	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickName();

	void	display(); // Display a contact
};

#endif
