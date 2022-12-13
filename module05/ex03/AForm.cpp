#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
	return "form grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "form grade too low";
}

const char* AForm::FormNotSigned::what() const throw()
{
	return "form was not signed";
}

int AForm::_check(const int& grade)
{
	if (grade < MAXGRADE)
	{
		std::cout << "### Warning : " << grade << " grade is too high! ";
		std::cout << "Grade will be corrected to 1 ###" << std::endl;
		return MAXGRADE;
	}
	else if (grade > MINGRADE)
	{
		std::cout << "### Warning : " << grade << " grade is too low! ";
		std::cout << "Grade will be corrected to 150 ###" << std::endl;
		return MINGRADE;
	}
	else
		return grade;
}

AForm::AForm() : _name("Empty"), _target("Default"), _signGrade(150), _execGrade(150), _indicatorSign(false)
{
	std::cout << "Form default constructor called\t\t\t";
	std::cout << this << std::endl;
}

AForm::AForm(const std::string &name, const std::string &target, const int &signGrade, const int &execGrade) :
	_name(name),
	_target(target),
	_signGrade(_check(signGrade)),
	_execGrade(_check(execGrade)),
	_indicatorSign(false)
{
	std::cout << "Form field constructor called\t\t\t";
	std::cout <<  this << std::endl;
}

AForm::AForm(const AForm &copy) :
	_name(copy.getName()),
	_target(copy.getTarget()),
	_signGrade(copy.getSignGrade()),
	_execGrade(copy.getExecGrade()),
	_indicatorSign (copy.getIndicatorSign())
{
	std::cout << "Form copy constructor called\t\t\t";
	std::cout <<  this << std::endl;
}

AForm::~AForm()
{
	std::cout << "Form destructor called\t\t\t\t";
	std::cout << this << std::endl;
}

AForm &	AForm::operator=(const AForm &assign)
{
	if (this != &assign)
		this->_indicatorSign = assign.getIndicatorSign();
	return *this;
}

const std::string & AForm::getName() const
{
	return _name;
}

const std::string & AForm::getTarget() const
{
	return _target;
}

const int & AForm::getSignGrade() const
{
	return _signGrade;
}

const int & AForm::getExecGrade() const
{
	return _execGrade;
}

const bool & AForm::getIndicatorSign() const
{
	return _indicatorSign;
}

void	AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _signGrade)
		throw AForm::GradeTooHighException();
	else
		_indicatorSign = true;
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (!_indicatorSign)
		throw AForm::FormNotSigned();
	else if (executor.getGrade() > _execGrade)
		throw AForm::GradeTooHighException();
	else
		action();
}

std::ostream & operator<<(std::ostream &out, const AForm &insert)
{
	out << insert.getName() << " form:" << std::endl << "*** signGrade = " << \
	insert.getSignGrade() << std::endl << "*** execGrade = " << \
	insert.getExecGrade() << std::endl << "is it signed? = " << \
	std::boolalpha << insert.getIndicatorSign() << std::endl;
	return out;
}
