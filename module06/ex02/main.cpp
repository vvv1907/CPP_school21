#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base * generate(void)
{
	int r = std::rand();

	if (r % 3 == 0)
	{
		std::cout << "generate A" << std::endl;
		return new A;
	}
	if (r % 3 == 1)
	{
		std::cout << "generate B" << std::endl;
		return new B;
	}
	std::cout << "generate C" << std::endl;
	return new C;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "type: class A pointer" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "type: class B pointer" << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "type: class C pointer" << std::endl;
	else
		std::cout << "Error: dynamic_cast returned NULL" << std::endl;
}

void identify(Base &p)
{
	A a;
	B b;
	C c;

	try
	{
		a = dynamic_cast<A&>(p);
		std::cout << "type: class A reference" << std::endl;
	}
	catch (std::exception &e) {}

	try
	{
		b = dynamic_cast<B&>(p);
		std::cout << "type: class B reference" << std::endl;
	}
	catch (std::exception &e) {}

	try 
	{
		c = dynamic_cast<C&>(p);
		std::cout << "type: class C reference" << std::endl;
	}
	catch (std::exception &e) {}
}

int main() 
{
	std::srand(time(NULL));

	Base *one = generate();
	Base *two = generate();
	Base *three = generate();
	
	identify(NULL);
	identify(*one);
	identify(one);
	identify(*two);
	identify(two);
	identify(*three);
	identify(three);

	delete one;
	delete two;
	delete three;

	return 0;
}
