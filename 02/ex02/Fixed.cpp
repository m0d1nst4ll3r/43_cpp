#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

const int	Fixed::_position = 8;

Fixed::Fixed( int n ) : _value(n << _position) {}

Fixed::Fixed( float f ) : _value(static_cast<int>(roundf(f * (1 << _position)))) {}

Fixed::Fixed( const Fixed& copy ) : _value(copy._value) {}

Fixed::~Fixed( void ) {}

std::ostream&	operator<<( std::ostream& out, const Fixed& op )
{
	out << op.toFloat();
	return out;
}

Fixed&	Fixed::operator=( const Fixed& op )
{
	if (this != &op)
		_value = op._value;
	return *this;
}

Fixed&	Fixed::operator++( void )
{
	_value++;
	return *this;
}

Fixed	Fixed::operator++( int )
{
	Fixed	tmp(*this);
	_value++;
	return tmp;
}

Fixed&	Fixed::operator--( void )
{
	_value--;
	return *this;
}

Fixed	Fixed::operator--( int )
{
	Fixed	tmp(*this);
	_value--;
	return tmp;
}

Fixed	Fixed::operator+( const Fixed& op ) const
{
	Fixed	tmp;
	tmp._value = _value + op._value;
	return tmp;
}

Fixed	Fixed::operator-( const Fixed& op ) const
{
	Fixed	tmp;
	tmp._value = _value - op._value;
	return tmp;
}

Fixed	Fixed::operator*( const Fixed& op ) const
{
	Fixed	tmp;
	tmp._value = static_cast<int>(
			(static_cast<long long>(_value) * static_cast<long long>(op._value)) >> _position
			);
	return tmp;
}

Fixed	Fixed::operator/( const Fixed& op ) const
{
	if (op._value == 0)
		throw std::domain_error("Fixed: division by zero");
	Fixed	tmp;
	tmp._value = static_cast<int>(
			(static_cast<long long>(_value) << _position) / op._value
			);
	return tmp;
}

bool	Fixed::operator==( const Fixed& op ) const
{
	return _value == op._value;
}

bool	Fixed::operator!=( const Fixed& op ) const
{
	return _value != op._value;
}

bool	Fixed::operator<( const Fixed& op ) const
{
	return _value < op._value;
}

bool	Fixed::operator>( const Fixed& op ) const
{
	return _value > op._value;
}

bool	Fixed::operator<=( const Fixed& op ) const
{
	return _value <= op._value;
}

bool	Fixed::operator>=( const Fixed& op ) const
{
	return _value >= op._value;
}

int		Fixed::getRawBits( void ) const
{
	return (_value);
}

void	Fixed::setRawBits( const int raw )
{
	_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(_value) / static_cast<float>(1 << _position));
}

int		Fixed::toInt( void ) const
{
	return (_value / (1 << _position));
}

Fixed&			Fixed::min( Fixed& a, Fixed& b)
{
	return a._value < b._value ? a : b;
}

const Fixed&	Fixed::min( const Fixed& a, const Fixed& b)
{
	return a._value < b._value ? a : b;
}

Fixed&			Fixed::max( Fixed& a, Fixed& b)
{
	return a._value > b._value ? a : b;
}

const Fixed&	Fixed::max( const Fixed& a, const Fixed& b)
{
	return a._value > b._value ? a : b;
}
