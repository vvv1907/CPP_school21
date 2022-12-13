#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : \
	AForm("Robotomy Request", target, _sign, _exec) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : \
	AForm(copy.getName(), copy.getTarget(), copy.getSignGrade(), copy.getExecGrade()) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

int RobotomyRequestForm::getRRFSign(void) const
{
	return _sign;
}
int RobotomyRequestForm::getRRFExec(void) const
{
	return _exec;
}

void	RobotomyRequestForm::action(void) const
{
	int fortune = std::rand();
	if (fortune % 2)
		std::cout << getName() << " makes some drilling noises... " << \
			getTarget() << " has been successfully robotomized!" << std::endl;
	else
		std::cout << getName() << ": " << getTarget() << "'s robotomy failed!" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
	(void)assign;
	return (*this);
}

const int RobotomyRequestForm::_sign = 72;
const int RobotomyRequestForm::_exec = 45;
