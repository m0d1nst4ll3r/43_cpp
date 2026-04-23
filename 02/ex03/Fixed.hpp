#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {


	public:

	Fixed( void );
	Fixed( int n );
	Fixed( float f );
	Fixed( const Fixed& copy );
	~Fixed( void );

	Fixed&	operator=( const Fixed& op );
	Fixed&	operator++( void );
	Fixed	operator++( int );
	Fixed&	operator--( void );
	Fixed	operator--( int );
	Fixed	operator+( const Fixed& op ) const;
	Fixed	operator-( const Fixed& op ) const;
	Fixed	operator*( const Fixed& op ) const;
	Fixed	operator/( const Fixed& op ) const;
	bool	operator==( const Fixed& op ) const;
	bool	operator!=( const Fixed& op ) const;
	bool	operator<( const Fixed& op ) const;
	bool	operator>( const Fixed& op ) const;
	bool	operator<=( const Fixed& op ) const;
	bool	operator>=( const Fixed& op ) const;

	int		getRawBits( void ) const;
	void	setRawBits( const int raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;

	static Fixed&			min( Fixed& a, Fixed& b);
	static const Fixed&		min( const Fixed& a, const Fixed& b);
	static Fixed&			max( Fixed& a, Fixed& b);
	static const Fixed&		max( const Fixed& a, const Fixed& b);

	private:

	int					_value;
	static const int	_position;

};

std::ostream&	operator<<( std::ostream& out, const Fixed& op );

#endif /* FIXED_H */
