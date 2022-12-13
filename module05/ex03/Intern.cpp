#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern::~Intern() {}

Intern & Intern::operator=(const Intern &assign)
{
	(void)assign;
	return (*this);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	AForm* result;
	AForm* (*Forms[3])(const std::string &name) = \
				{&PresidentialPardonForm::clone, \
					&RobotomyRequestForm::clone, \
					&ShrubberyCreationForm::clone};
	std::string	forms[3] = \
					{"presidential request", \
						"robotomy request", \
						"shrubbery request"};
	int i = 0;
	while (i < 3)
	{
		if (name == forms[i])
			break;
		i++;
	}
	switch (i)
	{
		case 3:
			std::cout << "Error: form doesn't exist!" << std::endl;
			return NULL;
		
		default:
			result = Forms[i](target);
			std::cout << "Intern creates " << *result;
	}
	return result;
}
