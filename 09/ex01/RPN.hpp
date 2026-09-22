#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
	public:

	RPN(const std::string& contents = "");
	~RPN();
	RPN(const RPN& toCopy);
	RPN& operator=(const RPN& op);

	double calculate();
	void display();

	private:

	std::stack<char>	_contents;
};

#endif /* RPN_HPP */
