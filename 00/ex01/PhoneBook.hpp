#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "Contact.hpp"

class PhoneBook {


	public:

	PhoneBook();
	bool	add();
	bool	search() const;


	private:

	Contact		_contactList[8];
	int			_numContacts;

	void	_display() const;

};

#endif /* PHONEBOOK_H */
