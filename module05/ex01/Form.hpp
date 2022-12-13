#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	const int			_signGrade;
	const int			_execGrade;
	bool				_indicatorSign;
	int					_check(const int &grade);

public:
	class	GradeTooHighException : public std::exception
	{
		const char* what() const throw();
	};
	
	class	GradeTooLowException : public std::exception
	{
		const char* what() const throw();
	};

	Form();
	Form(const std::string &name, const int &signGrade, const int &execGrade);
	Form(const Form &copy);
	
	~Form();

	Form & operator=(const Form &assign);

	const std::string	&getName() const;
	const int			&getSignGrade() const;
	const int			&getExecGrade() const;
	const bool			&getIndicatorSign() const;

	void 				beSigned(const Bureaucrat &b);
};

std::ostream & operator<<(std::ostream &out, const Form &insert);

#endif
