#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void) 
{
	std::cout << std::endl;
	Intern  someRandomIntern1;
	AForm*   rrf1;
	rrf1 = someRandomIntern1.makeForm("robotomy request", "Bender");
	delete rrf1;

	std::cout << std::endl;
	Intern  someRandomIntern2;
	AForm*   rrf2;
	rrf2 = someRandomIntern2.makeForm("shrubbery request", "Bender");
	delete rrf2;

	std::cout << std::endl;
	Intern  someRandomIntern3;
	AForm*   rrf3;
	rrf3 = someRandomIntern3.makeForm("presidential request", "Bender");
	delete rrf3;

	std::cout << std::endl;
	Intern  someRandomIntern4;
	AForm*   rrf4;
	rrf4 = someRandomIntern4.makeForm("bad request", "Bender");
	delete rrf4;

	return 0;
}
