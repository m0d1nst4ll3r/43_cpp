#include "Point.hpp"
#include <iostream>

bool	bsp( const Point& a, const Point& b, const Point& c, const Point& point );

int	main( void )
{
	Point	a(0, 0);
	Point	b(1, 1);
	Point	c(1, 0);
	Point	point(0.51f, 0.5f);
	std::cout << bsp(a, b, c, point) << '\n';
	return 0;
}
