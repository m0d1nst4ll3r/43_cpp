#include "RPN.hpp"
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>

namespace
{
	double recurseRPN(std::stack<char>& contents)
	{
		if (contents.empty())
			throw std::runtime_error("not a valid reverse polish notation");
		char	cur = contents.top();
		contents.pop();
		if (std::isdigit(cur))
			return (cur - '0');
		if (cur == '+')
			return (recurseRPN(contents) + recurseRPN(contents));
		if (cur == '*')
			return (recurseRPN(contents) * recurseRPN(contents));
		double res = recurseRPN(contents);
		if (cur == '-')
			return (recurseRPN(contents) - res);
		return (recurseRPN(contents) / res);
	}
}

RPN::RPN(const std::string& contents)
{
	std::stringstream	ss(contents);
	std::string			s;
	while (getline(ss, s, ' '))
	{
		if (!s.empty())
		{
			if (s.size() != 1 || (!std::isdigit(s[0]) && s[0] != '-' && s[0] != '+' && s[0] != '/' && s[0] != '*'))
				throw std::runtime_error("'" + s + "': not a digit or operand");
			_contents.push(s[0]);
		}
	}
}

RPN::~RPN() {}
RPN::RPN(const RPN& toCopy) : _contents(toCopy._contents) {}

RPN& RPN::operator=(const RPN& op)
{
	if (this != &op)
	{
		_contents = op._contents;
	}
	return *this;
}

void RPN::display()
{
	std::stack<char>	copy(_contents);
	std::cout << "\033[36mContents\033[0m:";
	while (!copy.empty())
	{
		std::cout << " " << copy.top();
		copy.pop();
	}
	std::cout << "\n";
}

double RPN::calculate()
{
	std::stack<char>	copy(_contents);
	double result = recurseRPN(copy);
	if (!copy.empty())
		throw std::runtime_error("not a valid reverse polish notation");
	return result;
}
