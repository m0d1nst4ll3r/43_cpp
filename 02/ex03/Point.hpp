#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point {


	public:

	Point( const float x = 0, const float y = 0 );
	Point( const Point& toCopy );
	~Point( void );

	Point&	operator=( const Point& op );

	Fixed	getX( void ) const;
	Fixed	getY( void ) const;

	private:

	Fixed	_x;
	Fixed	_y;

};

#endif /* POINT_H */
