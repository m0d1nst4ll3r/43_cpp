#include "Fixed.hpp"
#include <iostream>

const int	Fixed::_position = 8;

Fixed::Fixed( void ) : _value(0)
{
	std::cerr << "Default constructor called\n";
}

Fixed::~Fixed( void )
{
	std::cerr << "Destructor called\n";
}

Fixed::Fixed( const Fixed& copy ) : _value(copy._value)
{
	std::cerr << "Copy constructor called\n";
}

Fixed&	Fixed::operator=( const Fixed& op )
{
	std::cerr << "Copy assignment operator called\n";
	if (this != &op)
		_value = op._value;
	return *this;
}

int		Fixed::getRawBits( void ) const
{
	std::cerr << "getRawBits member function called\n";
	return (_value);
}

void	Fixed::setRawBits( const int raw )
{
	std::cerr << "setRawBits member function called\n";
	_value = raw;
}
