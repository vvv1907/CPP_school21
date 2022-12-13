#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int					_raw;
	static const int	_bits = 8;

public:
	Fixed();
	Fixed(const Fixed &copy);
	Fixed(const int value);
	Fixed(const float value);

	~Fixed();

	Fixed&	operator= (const Fixed &assign);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;

	bool	operator> (const Fixed &object) const;
	bool	operator< (const Fixed &object) const;
	bool	operator>= (const Fixed &object) const;
	bool	operator<= (const Fixed &object) const;
	bool	operator== (const Fixed &object) const;
	bool	operator!= (const Fixed &object) const;

	Fixed	operator+ (const Fixed &object) const;
	Fixed	operator- (const Fixed &object) const;
	Fixed	operator* (const Fixed &object) const;
	Fixed	operator/ (const Fixed &object) const;

	Fixed 	operator++ (int);
	Fixed&	operator++ (void);
	Fixed	operator-- (int);
	Fixed&	operator-- (void);

	static Fixed&		min(Fixed &number1, Fixed &number2);
	static const Fixed&	min(const Fixed &number1, const Fixed &number2);
	static Fixed&		max(Fixed &number1, Fixed &number2);
	static const Fixed&	max(const Fixed &number1, const Fixed &number2);
};

std::ostream& operator<< (std::ostream &out, const Fixed &insert);

#endif
