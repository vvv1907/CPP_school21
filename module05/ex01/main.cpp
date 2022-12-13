#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat b("Franz", 4);
	Form z;
	Form f("First", 3, 1);
	Form s("Second", 200, 0);
	Form t(f);
	std::cout << std::endl;

	b.signForm(z);
	std::cout << b << std::endl << z << std::endl;
	b.signForm(f);
	std::cout << b << std::endl << f << std::endl;
	b.signForm(s);
	std::cout << b << std::endl << s << std::endl;
	b.signForm(t);
	std::cout << b << std::endl << t << std::endl;
	return 0;
}
