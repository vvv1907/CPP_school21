#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int					_raw;
	static const int	_bits = 8;

public:
	Fixed();
	Fixed(const Fixed &copy);

	~Fixed();

	Fixed& operator= (const Fixed &assign);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
