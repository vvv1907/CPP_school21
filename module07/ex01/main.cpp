#include "iter.hpp"

int main()
{
	std::string s[] = {"Hello,", "world!"};
	char		c[] = {'a', 'b', 'c', 'd', 'e'};
	int			i[] = {-5, 0, 21, 42};
	double		d[] = {1.2, 3.4, 5.6};

	::iter(s, 2, &printer);
	std::cout << std::endl;
	::iter(c, sizeof(c), &printer);
	std::cout << std::endl;
	::iter(i, sizeof(i) / sizeof(int), &printer);
	std::cout << std::endl;
	::iter(d, sizeof(d) / sizeof(double), &printer);
	std::cout << std::endl;

	return 0;
}
