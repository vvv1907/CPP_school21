#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	static const int	_sign;
	static const int	_exec;
	
	RobotomyRequestForm();

	RobotomyRequestForm & operator=(const RobotomyRequestForm &assign);

public:
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);

	~RobotomyRequestForm();

	int		getRRFSign(void) const;
	int		getRRFExec(void) const;

	void	action(void) const;
};

#endif
