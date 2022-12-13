#include <string>
#include <iostream>

int main(void)
{
	std::string originStr = "HI THIS IS BRAIN";
	std::string *stringPTR = &originStr;
	std::string &stringREF = originStr;

    std::cout << "---------------------------------" << std::endl;
	std::cout << "String address:    " << &originStr << std::endl;
	std::cout << "Pointer address:   " << stringPTR	<< std::endl;
	std::cout << "Reference address: " << &stringREF << std::endl;
    std::cout << "---------------------------------" << std::endl;
	std::cout << "String value:    " << originStr	<< std::endl;
	std::cout << "Pointer value:   " << *stringPTR	<< std::endl;
	std::cout << "Reference value: " << stringREF	<< std::endl;
    std::cout << "---------------------------------" << std::endl;

	return (0);
}
