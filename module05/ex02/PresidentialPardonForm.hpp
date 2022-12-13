#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	static const int	_sign;
	static const int	_exec;
	
	PresidentialPardonForm();

	PresidentialPardonForm & operator=(const PresidentialPardonForm &assign);

public:
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);

	~PresidentialPardonForm();

	int		getPPFSign(void) const;
	int		getPPFExec(void) const;
	
	void	action(void) const;
};

#endif
