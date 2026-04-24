#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {


	public:
	Contact(const std::string& firstName = "",
			const std::string& lastName = "",
			const std::string& nickName = "",
			const std::string& phoneNumber = "",
			const std::string& darkestSecret = "");

	const std::string&	getFirstName() const;
	const std::string&	getLastName() const;
	const std::string&	getNickName() const;

	void	display() const;


	private:

	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

};

#endif /* CONTACT_H */
