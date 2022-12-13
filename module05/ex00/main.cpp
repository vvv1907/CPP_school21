#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat a;
	std::cout << a << std::endl << std::endl;

	Bureaucrat b("First", 1);
	std::cout << b << std::endl << std::endl;

	try
	{
		Bureaucrat c("Second", 200);
		std::cout << c << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	
	Bureaucrat d(b);
	std::cout << d << std::endl << std::endl;

	try
	{
		a.decrementGrade();
		std::cout << a << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	try
	{
		b.incrementGrade();
		std::cout << b << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	try
	{
		d.decrementGrade();
		std::cout << d << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	return 0;
}
