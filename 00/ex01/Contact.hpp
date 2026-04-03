#ifndef CONTACT
# define CONTACT

class Contact
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
	public:
	Contact()
	{
	};
	Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
	{
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
	std::string	getPhoneNumber()
	{
		return phoneNumber;
	};
	std::string	getDarkestSecret()
	{
		return darkestSecret;
	};
};

#endif
