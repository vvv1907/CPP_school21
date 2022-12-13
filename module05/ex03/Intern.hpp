#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:

	Intern();
	Intern(const Intern &copy);

	~Intern();

	Intern & operator=(const Intern &assign);
	
	AForm * makeForm(const std::string &name, const std::string &target);
};

#endif
