#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return "form grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "form grade too low";
}

int Form::_check(const int& grade)
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

Form::Form() : _name("Empty"), _signGrade(150), _execGrade(150), _indicatorSign(false)
{
	std::cout << "Form default constructor called\t\t\t";
	std::cout << this << std::endl;
}

Form::Form(const std::string &name, const int &signGrade, const int &execGrade) :
	_name(name),
	_signGrade(_check(signGrade)),
	_execGrade(_check(execGrade)),
	_indicatorSign(false)
{
	std::cout << "Form field constructor called\t\t\t";
	std::cout <<  this << std::endl;
}

Form::Form(const Form &copy) :
	_name(copy.getName()),
	_signGrade(copy.getSignGrade()),
	_execGrade(copy.getExecGrade()),
	_indicatorSign (copy.getIndicatorSign())
{
	std::cout << "Form copy constructor called\t\t\t";
	std::cout <<  this << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called\t\t\t\t";
	std::cout << this << std::endl;
}

Form &	Form::operator=(const Form &assign)
{
	if (this != &assign)
		this->_indicatorSign = assign.getIndicatorSign();
	return *this;
}

const std::string & Form::getName() const
{
	return _name;
}

const int & Form::getSignGrade() const
{
	return _signGrade;
}

const int & Form::getExecGrade() const
{
	return _execGrade;
}

const bool & Form::getIndicatorSign() const
{
	return _indicatorSign;
}

void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _signGrade)
		_indicatorSign = true;
	else
		throw Form::GradeTooHighException();
}

std::ostream & operator<<(std::ostream &out, const Form &insert)
{
	out << insert.getName() << " form:" << std::endl << "*** signGrade = " << \
	insert.getSignGrade() << std::endl << "*** execGrade = " << \
	insert.getExecGrade() << std::endl << "is it signed? = " << \
	std::boolalpha << insert.getIndicatorSign() << std::endl;
	return out;
}
