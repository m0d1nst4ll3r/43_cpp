#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__
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

#endif /* __PHONEBOOK_H__ */
