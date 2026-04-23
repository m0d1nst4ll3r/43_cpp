#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point {


	public:

	Point( void );
	Point( const float x, const float y );
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
