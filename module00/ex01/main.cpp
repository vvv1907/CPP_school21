#include <string>
#include <iostream>
#include "contact.hpp"
#include "phoneBook.hpp"

int main(void)
{
	std::string beginMessage = "Please enter one of the following commands: ";
	std::string endMessage = "ADD, SEARCH, EXIT (in upper case)";
	std::string command;
	PhoneBook	phoneBook;

	std::cout << beginMessage << endMessage << std::endl;
	while (std::getline(std::cin, command))
	{
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else
			std::cout << "Invalid command, try again!" << std::endl;
	std::cout << beginMessage << endMessage << std::endl;
	}
	return (0);
}
