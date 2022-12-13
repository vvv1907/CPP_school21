#include "convert.hpp"

const char*	Convert::BadStringException::what() const throw()
{
	return "Error: wrong input string!";
}

Convert::Convert() : _err(false), _val(0.0f), _input("") {}

Convert::Convert(const std::string &input) : _err(false), _val(0.0f), _input(input)
{
	try
	{
		char* str = NULL;
		if (std::isprint(_input[0]) && !std::isdigit(_input[0]) && _input[1] == '\0')
			_val = _input[0];
		else
		{
			_val = std::strtod(_input.c_str(), &str);
			if (_val == 0.0f && (_input[0] != '+' && _input[0] != '-' && !std::isdigit(_input[0])))
				throw Convert::BadStringException();
			if (*str && strcmp(str, "f"))
				throw Convert::BadStringException();
		}
	}
	catch(const std::exception &e)
	{
		_err = true;
		std::cerr << e.what() << std::endl;
	}
}

Convert::Convert(const Convert& copy) : _err(copy.getErr()), _val(copy.getVal()), _input(copy.getInput()) {}

bool	Convert::getErr() const
{
	return _err;
}

double	Convert::getVal() const
{
	return _val;
}

std::string	Convert::getInput() const
{
	return _input;
}

char	Convert::getChar() const
{
	return static_cast<char>(_val);
}

int		Convert::getInt() const
{
	return static_cast<int>(_val);
}

float	Convert::getFloat() const
{
	return static_cast<float>(_val);
}

double	Convert::getDouble() const
{
	return static_cast<double>(_val);
}

static void	printChar(std::ostream &out, const Convert &insert)
{
	out << "char: ";
	if (std::isnan(insert.getVal()) || \
		std::isinf(insert.getVal()) || \
			insert.getVal() > static_cast<double>(std::numeric_limits<char>::max()) || \
			insert.getVal() < static_cast<double>(std::numeric_limits<char>::min()))
	{
		out << "impossible" << std::endl;
		return ;
	}
	if (!std::isprint(insert.getChar()))
	{
		out << "Non displayable" << std::endl;
		return ;
	}
	out << "'" << insert.getChar() << "'"<< std::endl;
}

static void	printInt(std::ostream &out, const Convert &insert)
{
	out << "int: ";
	if (std::isnan(insert.getVal()) || \
		std::isinf(insert.getVal()) || \
				insert.getVal() > static_cast<double>(std::numeric_limits<int>::max()) || \
				insert.getVal() < static_cast<double>(std::numeric_limits<int>::min()))
	{
		out << "impossible" << std::endl;
		return ;
	}
	out << insert.getInt() << std::endl;
}

static void	printFloat(std::ostream &out, const Convert &insert)
{
	out << "float: ";
	if (std::isnan(insert.getFloat()) || std::isinf(insert.getFloat()))
	{
		out << std::showpos << insert.getFloat() << "f" << std::endl;
		return ;
	}
	if (floor(insert.getVal()) == ceil(insert.getVal()))
		out << insert.getFloat() << ".0f" << std::endl;
	else
		out << insert.getFloat() << "f" << std::endl;
}

static void	printDouble(std::ostream &out, const Convert &insert)
{
	out << "double: ";
	if (std::isnan(insert.getVal()) || std::isinf(insert.getVal()))
	{
		out << std::showpos << insert.getDouble() << std::endl;
		return ;
	}
	if (floor(insert.getVal()) == ceil(insert.getVal()))
		out << insert.getDouble() << ".0" << std::endl;
	else
		out << insert.getDouble() << std::endl;
}

Convert::~Convert() {}

Convert & Convert::operator=(const Convert &assign)
{
	if (this != &assign)
	{
		this->_err = assign.getErr();
		this->_val = assign.getVal();
		this->_input = assign.getInput();
	}
	return *this;
}

std::ostream & operator<<(std::ostream &out, const Convert &insert)
{
	if (insert.getErr())
		return out;
	printChar(out, insert);
	printInt(out, insert);
	printFloat(out, insert);
	printDouble(out, insert);
	return out;
}
