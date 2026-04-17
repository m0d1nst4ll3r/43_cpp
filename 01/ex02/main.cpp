#include <string>
#include <iostream>

int	main( void )
{
	const std::string	myStr = "HI THIS IS BRAIN";
	const std::string*	stringPTR = &myStr;
	const std::string&	stringREF = myStr;

	std::cout << "Address of myStr:\t\t\t\t" << &myStr << '\n';
	std::cout << "Address contained in stringPTR:\t\t\t" << stringPTR << '\n';
	std::cout << "Address contained in stringREF:\t\t\t" << &stringREF << '\n';

	std::cout << "Value of myStr:\t\t\t\t\t" << myStr << '\n';
	std::cout << "Value pointed by stringPTR:\t\t\t" << *stringPTR << '\n';
	std::cout << "Value pointed by stringREF:\t\t\t" << stringREF << '\n';
}
