#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	const std::string	_target;
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

	class	FormNotSigned : public std::exception
	{
		const char* what() const throw();
	};

	AForm();
	AForm(const std::string &name, const std::string &target, const int &signGrade, const int &execGrade);
	AForm(const AForm &copy);
	
	virtual ~AForm();

	AForm & operator=(const AForm &assign);

	const std::string	&getName() const;
	const std::string	&getTarget() const;
	const int			&getSignGrade() const;
	const int			&getExecGrade() const;
	const bool			&getIndicatorSign() const;

	void 				beSigned(const Bureaucrat &b);
	void				execute(const Bureaucrat &executor) const;
	virtual void		action(void) const = 0;
};

std::ostream & operator<<(std::ostream &out, const AForm &insert);

#endif
