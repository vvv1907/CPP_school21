#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <cstring>
# include <limits>
# include <cmath>

class Convert
{
private:
	bool		_err;
	double		_val;
	std::string	_input;

public:
	class BadStringException: public std::exception
	{
		const char* what() const throw();
	};

	Convert();
	Convert(const std::string &input);
	Convert(const Convert &copy);

	~Convert();

	Convert &	operator=(const Convert &assign);

	bool		getErr() const;
	double		getVal() const;
	std::string	getInput() const;

	char		getChar() const;
	int			getInt() const;
	float		getFloat() const;
	double		getDouble() const;	
};

std::ostream & operator<<(std::ostream &out, const Convert &insert);

#endif
