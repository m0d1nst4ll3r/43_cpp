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
	Contact(const std::string &firstName, const std::string &lastName, const std::string &nickName, const std::string &phoneNumber, const std::string &darkestSecret);

	// Getters
	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickName() const;

	void	display() const; // Display a contact
};

#endif
