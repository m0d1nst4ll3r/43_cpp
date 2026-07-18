#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main()
{
	Bureaucrat	bob("Bob", 150);
	Bureaucrat	john("John", 1);
	Bureaucrat	dflBur;
	Form		groceryList("Grocery list", 150, 150);
	Form		topSecret("54B", 20, 10);
	Form		dflForm;

	std::cout << "Bureaucrats:\n\t" << bob << "\n\t" << john << "\n\t" << dflBur << "\n\n";
	std::cout << "Forms:\n\t" << groceryList << "\n\t" << topSecret << "\n\t" << dflForm << "\n\n";

	std::cout << "Attempt to declare form with too high signing requirements:\n";
	try { Form bug("Bug", 0, 2); }
	catch (std::exception& e) { std::cerr << "Form declaration failed: " << e.what() << ".\n"; }

	std::cout << "Attempt to declare form with too low signing requirements:\n";
	try { Form bug("Bug", 150, 151); }
	catch (std::exception& e) { std::cerr << "Form declaration failed: " << e.what() << ".\n"; }

	std::cout << "\n";

	bob.signForm(topSecret);
	bob.signForm(groceryList);
	john.signForm(topSecret);
	john.signForm(topSecret);

	std::cout << "\n" << topSecret << "\n";
}