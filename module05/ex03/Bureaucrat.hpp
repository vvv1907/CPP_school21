#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

# define MAXGRADE 1
# define MINGRADE 150

class AForm;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	
	class	GradeTooHighException : public std::exception
	{
		const char* what() const throw();
	};
	
	class	GradeTooLowException : public std::exception
	{
		const char* what() const throw();
	};
	
	Bureaucrat();
	Bureaucrat(std::string const &name, const int &grade);
	Bureaucrat(const Bureaucrat &copy);
	
	~Bureaucrat();

	Bureaucrat &		operator=(const Bureaucrat &assign);
	
	const std::string	&getName() const;
	const int			&getGrade() const;

	void				incrementGrade(void);
	void				decrementGrade(void);
	void 				signForm(AForm &f);
	void 				executeForm(AForm const &form) const;
};

std::ostream & operator<<(std::ostream &out, const Bureaucrat &insert);

#endif
