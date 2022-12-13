#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_raw = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_raw = value * (1 << _bits);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_raw = roundf(value * (1 << _bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return _raw;
}

void	Fixed::setRawBits(int const raw)
{
	_raw = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)_raw / (float)(1 << _bits);
}

int		Fixed::toInt(void) const
{
	return (int)_raw / (int)(1 << _bits);
}

Fixed& Fixed::operator= (const Fixed &assign)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assign) // self-assignment check
		_raw = assign.getRawBits();
	return *this;
}

std::ostream& operator<< (std::ostream &out, const Fixed &insert)
{
	out << insert.toFloat();
	return out;
}
