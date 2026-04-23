#include "Point.hpp"
#include "Fixed.hpp"

Point::Point( void ) : _x(0), _y(0) {}
Point::Point( const float x, const float y ) : _x(x), _y(y) {}
Point::Point( const Point& toCopy ) : _x(toCopy._x), _y(toCopy._y) {}
Point::~Point( void ) {}

Point&	Point::operator=( const Point& op)
{
	if (this != &op)
	{
		_x = op._x;
		_y = op._y;
	}
	return *this;
}

Fixed	Point::getX( void ) const { return _x; }
Fixed	Point::getY( void ) const { return _y; }
