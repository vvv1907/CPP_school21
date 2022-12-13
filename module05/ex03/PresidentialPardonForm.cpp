#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : \
	AForm("Presidential Pardon", target, _sign, _exec) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : \
	AForm(copy.getName(), copy.getTarget(), copy.getSignGrade(), copy.getExecGrade()) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

int PresidentialPardonForm::getPPFSign(void) const
{
	return _sign;
}
int PresidentialPardonForm::getPPFExec(void) const
{
	return _exec;
}

void PresidentialPardonForm::action(void) const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

AForm * PresidentialPardonForm::clone(const std::string& name)
{
	return new PresidentialPardonForm(name);
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
	(void)assign;
	return (*this);
}

const int PresidentialPardonForm::_sign = 25;
const int PresidentialPardonForm::_exec = 5;
