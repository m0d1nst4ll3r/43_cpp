#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {


	public:

	Fixed( const Fixed& copy );
	Fixed( int n = 0 );
	Fixed( float f );
	~Fixed( void );

	Fixed&	operator=( const Fixed& op );

	int		getRawBits( void ) const;
	void	setRawBits( const int raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;


	private:

	int					_value;
	static const int	_position;

};

std::ostream&	operator<<( std::ostream& out, const Fixed& op );

#endif /* FIXED_H */
