#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>

class Contact {


	public:
	Contact();
	Contact(const std::string& firstName, const std::string& lastName, const std::string& nickName, const std::string& phoneNumber, const std::string& darkestSecret);

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

#endif /* __CONTACT_H__ */
