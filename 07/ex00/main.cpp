#include "whatever.hpp"
#include <iostream>
#include <string>

int	main()
{
	int	a = 2, b = 5;
	std::string sa = "string1", sb = "string2";
	std::cout << "Before, a[" << a << "], b[" << b << "], sa[" << sa << "], sb[" << sb << "]\n";
	swap(a, b);
	swap(sa, sb);
	std::cout << "After, a[" << a << "], b[" << b << "], sa[" << sa << "], sb[" << sb << "]\n";
	std::cout << "Min a/b: " << min(a,b) << " - Min sa/sb: " << min(sa,sb) << "\n";
	std::cout << "Max a/b: " << max(a,b) << " - Max sa/sb: " << max(sa,sb) << "\n";
	return 0;
}