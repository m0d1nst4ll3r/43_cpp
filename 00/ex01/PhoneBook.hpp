#ifndef PHONEBOOK
# define PHONEBOOK
# include <iostream>
# include <limits>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
	// Private data members
	Contact		contactList[8];
	int			numContacts = 0;

	// Private methods
	void	display(); // Display phonebook contents
	void	shiftContacts(); // Shift contacts to make room for a new one
	void	incrementContacts(); // Up to 8
	void	addContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);

	// Public methods
	public:
	PhoneBook(); // Empty constructor
	bool	add(); // Add new contact
	bool	search(); // Search in phonebook
};

#endif
