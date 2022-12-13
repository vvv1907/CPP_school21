#include "Fixed.hpp"

Fixed::Fixed()
{
	_raw = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::Fixed(const int value)
{
	_raw = value * (1 << _bits);
}

Fixed::Fixed(const float value)
{
	_raw = roundf(value * (1 << _bits));
}

Fixed::~Fixed() {}

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
	if (this != &assign) // self-assignment check
		_raw = assign.getRawBits();
	return *this;
}

std::ostream& operator<< (std::ostream &out, const Fixed &insert)
{
	out << insert.toFloat();
	return out;
}

// comparison operators:

bool	Fixed::operator> (const Fixed &object) const
{
	return (_raw > object.getRawBits());
}

bool	Fixed::operator< (const Fixed &object) const
{
	return (_raw < object.getRawBits());
}

bool	Fixed::operator>= (const Fixed &object) const
{
	return (_raw >= object.getRawBits());
}

bool	Fixed::operator<= (const Fixed &object) const
{
	return (_raw <= object.getRawBits());
}

bool	Fixed::operator== (const Fixed &object) const
{
	return (_raw == object.getRawBits());
}

bool	Fixed::operator!= (const Fixed &object) const
{
	return (_raw != object.getRawBits());
}

// arithmetic operators:

Fixed	Fixed::operator+ (const Fixed &object) const
{
	Fixed result;
	result = this->toFloat() + object.toFloat();
	return result;
}

Fixed	Fixed::operator- (const Fixed &object) const
{
	Fixed result;
	result = this->toFloat() - object.toFloat();
	return result;
}

Fixed	Fixed::operator* (const Fixed &object) const
{
	Fixed result;
	result = this->toFloat() * object.toFloat();
	return result;
}

Fixed	Fixed::operator/ (const Fixed &object) const
{
	Fixed result;
	result = this->toFloat() / object.toFloat();
	return result;
}

// increment and decrement:

Fixed	Fixed::operator++ (int)
{
	Fixed result(*this);
	this->_raw++;
	return result;
}

Fixed&	Fixed::operator++ (void)
{
	this->_raw++;
	return (*this);
}

Fixed	Fixed::operator-- (int)
{
	Fixed result(*this);
	this->_raw--;
	return result;
}

Fixed&	Fixed::operator-- (void)
{
	this->_raw--;
	return (*this);
}

// min and max:

Fixed&	Fixed::min(Fixed &number1, Fixed &number2)
{
	if (number1 < number2)
		return number1;
	else
		return number2;
}

const Fixed&	Fixed::min(const Fixed &number1, const Fixed &number2)
{
	if (number1 < number2)
		return number1;
	else
		return number2;
}

Fixed&	Fixed::max(Fixed &number1, Fixed &number2)
{
	if (number1 > number2)
		return number1;
	else
		return number2;
}

const Fixed&	Fixed::max(const Fixed &number1, const Fixed &number2)
{
	if (number1 > number2)
		return number1;
	else
		return number2;
}
