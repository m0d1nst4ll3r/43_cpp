#include "Fixed.hpp"
#include <iostream>

int	main( void )
{
	std::cout << "Subject tests:\n";

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "Custom tests:\n";

	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;

	std::cout << Fixed(5.05f) + Fixed(2.01f) << '\n';
	std::cout << Fixed(5.05f) - Fixed(2.01f) << '\n';
	std::cout << Fixed(5.05f) * Fixed(2.01f) << '\n';
	std::cout << Fixed(100) * Fixed(100) << '\n';
	std::cout << Fixed(1000) * Fixed(1000) << '\n';
	std::cout << Fixed(1) / Fixed(128) << '\n';
	std::cout << Fixed::min(Fixed(1), Fixed(2)) << '\n';
	std::cout << Fixed::max(Fixed(1), Fixed(2)) << '\n';

	std::cout << Fixed(-5.05f) + Fixed(-2.01f) << '\n';
	std::cout << Fixed(-5.05f) - Fixed(-2.01f) << '\n';
	std::cout << Fixed(-5.05f) * Fixed(2.01f) << '\n';
	std::cout << Fixed(100) * Fixed(-100) << '\n';
	std::cout << Fixed(-1000) * Fixed(-1000) << '\n';
	std::cout << Fixed(1) / Fixed(-128) << '\n';
	std::cout << Fixed::min(Fixed(-1), Fixed(-2)) << '\n';
	std::cout << Fixed::max(Fixed(-1), Fixed(-2)) << '\n';
	std::cout << (Fixed(-1) == Fixed(-1)) << '\n';
	std::cout << (Fixed(-2) == Fixed(-1)) << '\n';
	std::cout << (Fixed(-1) != Fixed(-1)) << '\n';
	std::cout << (Fixed(-2) != Fixed(-1)) << '\n';
	std::cout << (Fixed(-1) < Fixed(2)) << '\n';
	std::cout << (Fixed(-2) > Fixed(-1)) << '\n';
	std::cout << (Fixed(-1) <= Fixed(-1)) << '\n';
	std::cout << (Fixed(-2) >= Fixed(-1)) << '\n';

	Fixed c = 3.56f;
	std::cout << c << '\n';

	try { std::cout << Fixed(1) / Fixed(0) << '\n'; }
	catch (...)	{ std::cout << "Exception caught\n"; }

	std::cout << "Reached end of tests\n";

	return 0;
}
