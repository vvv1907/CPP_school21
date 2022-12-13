#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << std::endl << "\t*** Creating Bureaucrat objects ***" << std::endl;
	std::cout << std::endl;
	Bureaucrat b1("Senior", 1);
	Bureaucrat b2("Middle", 15);
	Bureaucrat b3("Junior", 45);
	Bureaucrat b4("Intern", 130);

	std::cout << std::endl << "\t*** Creating Form objects ***" << std::endl;
	std::cout << std::endl;
	AForm*f1 = new PresidentialPardonForm("Man");
	AForm*f2 = new RobotomyRequestForm("Bender");
	AForm*f3 = new ShrubberyCreationForm("Home");

	std::cout << std::endl << "\t*** Look at our Bureaucrats... ***" << std::endl;
	std::cout << std::endl;
	std::cout << b1 << std::endl << b2 << std::endl << b3 << std::endl << b4;
	std::cout << std::endl;
	std::cout << std::endl << "\t*** and our Forms: ***" << std::endl;
	std::cout << std::endl;
	std::cout << *f1 << std::endl << *f2 << std::endl << *f3;

	std::cout << std::endl << "\t*** Let's try to execute anything ***" << std::endl;
	std::cout << std::endl;
	b1.executeForm(*f1);
	b1.executeForm(*f2);
	b1.executeForm(*f3);

	std::cout << std::endl << "\t*** But first need to sign the forms ***" << std::endl;
	std::cout << std::endl;
	b4.signForm(*f1);
	b2.signForm(*f1);
	b3.signForm(*f2);
	b4.signForm(*f3);

	std::cout << std::endl << "\t*** Here are our signed forms: ***" << std::endl;
	std::cout << std::endl;
	std::cout << *f1 << std::endl << *f2 << std::endl << *f3;

	std::cout << std::endl << "\t*** And let's try to execute again ***" << std::endl;
	std::cout << std::endl;
	b2.executeForm(*f1);
	b1.executeForm(*f1);
	b4.executeForm(*f2);
	b3.executeForm(*f2);
	b4.executeForm(*f3);

	std::cout << std::endl << "\t*** Don't forget to destroy Form's objects ***" << std::endl;
	std::cout << std::endl;
	delete f3;
	delete f2;
	delete f1;
	std::cout << std::endl << "\t*** ...and Bureaucrat's objects ***" << std::endl << std::endl;

	return 0;
}
