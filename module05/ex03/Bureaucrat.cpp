#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade too low";
}

Bureaucrat::Bureaucrat() : _name("Noname"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called\t\t";
	std::cout <<  this << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, const int &grade) : \
												_name(name), _grade(grade)
{
	if (grade > MINGRADE)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < MAXGRADE)
		throw Bureaucrat::GradeTooHighException();	
	std::cout << "Bureaucrat field constructor called\t\t";
	std::cout <<  this << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : \
							_name(copy.getName()), _grade(copy.getGrade())
{
	std::cout << "Bureaucrat copy constructor called\t\t";
	std::cout <<  this << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called\t\t\t";
	std::cout <<  this << std::endl;
}

Bureaucrat &	Bureaucrat::operator=(const Bureaucrat &assign)
{
	if (this != &assign)
		this->_grade = assign._grade;
	return *this;
}

const std::string &	Bureaucrat::getName() const
{
	return _name;
}

const int &	Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::incrementGrade()
{
	if (_grade <= MAXGRADE)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade >= MINGRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

void	Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign " << f.getName() << \
		" because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't execute " << form.getName() << \
		" because " << e.what() << std::endl;
	}
}

std::ostream& operator<< (std::ostream &out, const Bureaucrat &insert)
{
	out << insert.getName() << ", bureaucrat grade " << insert.getGrade();
	return out;
}
