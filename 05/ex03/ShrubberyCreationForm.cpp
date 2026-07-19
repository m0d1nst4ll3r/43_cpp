#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cerrno>
#include <cstring>

namespace
{
	void	openFile(const char* filename, std::ofstream& file)
	{
		file.open(filename, std::ios::app);
		if (!file)
			throw std::runtime_error(std::string("'") + filename + "': " + std::strerror(errno));
	}

	void	writeTrees(std::ofstream& file)
	{
		file << "\n";
		file << "               ,@@@@@@@,\n";
		file << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
		file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
		file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
		file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
		file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
		file << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
		file << "       |o|        | |         | |\n";
		file << "       |.|        | |         | |\n";
		file << "    \\\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";
	}
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &toCopy)
	: AForm("Shrubbery Creation", 145, 137), _target(toCopy._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &op)
{
	if (this != &op)
		_target = op._target;
	return *this;
}

void ShrubberyCreationForm::executeInternal() const
{
	std::ofstream	file;
	openFile((_target + "_shrubbery").c_str(), file); // Will throw exception if it can't open file
	writeTrees(file);
}