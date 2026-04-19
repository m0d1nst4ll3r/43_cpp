#ifndef __FIXED_H__
#define __FIXED_H__

class Fixed {


	public:

	Fixed( void );
	Fixed( const Fixed& copy );
	~Fixed( void );

	int		getRawBits( void ) const;
	void	setRawBits( const int raw );

	Fixed&	operator=( const Fixed& op );

	private:

	int					_value;
	static const int	_position;

};

#endif /* __FIXED_H__ */
