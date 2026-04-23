#include "Fixed.hpp"
#include "Point.hpp"

namespace {

	// Get position of point relative to line a--b
	// If pos  < 0 then point is  left of line a--b
	// If pos  > 0 then point is right of line a--b
	// If pos == 0 then point is    ON    line a--b
	// Does not calculate real distance to line
	Fixed	posToLine( const Point& a, const Point& b, const Point& point)
	{
		return ((b.getY() - a.getY()) * (point.getX() - a.getX()) - (b.getX() - a.getX()) * (point.getY() - a.getY()));
	}

}

// a, b, c	- vertices of triangle
// point	- point to test
// returns true if point is in triangle
// returns false if point is a vertex or on an edge
bool	bsp( const Point& a, const Point& b, const Point& c, const Point& point )
{
	Fixed	posToAB = posToLine(a, b, point);
	Fixed	posToBC = posToLine(b, c, point);
	Fixed	posToCA = posToLine(c, a, point);
	return ((posToAB > Fixed(0) && posToBC > Fixed(0) && posToCA > Fixed(0))
			|| (posToAB < Fixed(0) && posToBC < Fixed(0) && posToCA < Fixed(0)));
}
