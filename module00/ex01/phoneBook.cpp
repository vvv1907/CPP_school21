#include "phoneBook.hpp"

PhoneBook::PhoneBook() { this->_index = 0; }

PhoneBook::~PhoneBook() {}

void    PhoneBook::printSubstr(std::string str)
{
	if (str.length() >= 10)
		std::cout << "|" << str.substr(0, 9) << ".";
    else
		std::cout << "|" << std::setw(10) << str;
}

void    PhoneBook::displayContact()
{
    std::string output;
    
    std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;

    for (int index = 1; index <= std::min(_index, PHONEBOOK_SIZE); index++)
    {
        std::cout << "|" << std::setw(10) << index;
		output = contacts[index-1].getFirstName();
		printSubstr(output);
		output = contacts[index-1].getLastName();
		printSubstr(output);
        output = contacts[index-1].getNickname();
		printSubstr(output);
        std::cout << "|" << std::endl;
    }
    std::cout << "+----------+----------+----------+----------+" << std::endl;
}

bool PhoneBook::strIsspace(std::string str)
{
    for (std::string::const_iterator it = str.cbegin(); it != str.cend(); it++)
    {
        if (!isspace(*it))
            return (false);
    }
    return (true);
}

void    PhoneBook::addContact()
{
	std::string	input;
    while (true)
    {
        std::cout << "Please enter first name: ";
	    std::getline (std::cin, input);
        if (strIsspace(input))
            std::cout << "The contact field cann't be empty, try again!" << std::endl;
        else
        {
	        this->contacts[this->_index % PHONEBOOK_SIZE].setFirstName(input);
            break ;
        }
    }
    while (true)
    {
        std::cout << "Please enter last name: ";
	    std::getline (std::cin, input);
        if (strIsspace(input))
            std::cout << "The contact field cann't be empty, try again!" << std::endl;
        else
        {
	        this->contacts[this->_index % PHONEBOOK_SIZE].setLastName(input);
            break ;
        }
    }
    while (true)
    {
        std::cout << "Please enter nickname: ";
	    std::getline (std::cin, input);
        if (strIsspace(input))
            std::cout << "The contact field cann't be empty, try again!" << std::endl;
        else
        {
	        this->contacts[this->_index % PHONEBOOK_SIZE].setNickname(input);
            break ;
        }
    }
    while (true)
    {
        std::cout << "Please enter phone number: ";
	    std::getline (std::cin, input);
        if (strIsspace(input))
            std::cout << "The contact field cann't be empty, try again!" << std::endl;
        else
        {
	        this->contacts[this->_index % PHONEBOOK_SIZE].setPhoneNumber(input);
            break ;
        }
    }
	while (true)
    {
        std::cout << "Please enter darkest secret: ";
	    std::getline (std::cin, input);
        if (strIsspace(input))
            std::cout << "The contact field cann't be empty, try again!" << std::endl;
        else
        {
	        this->contacts[this->_index % PHONEBOOK_SIZE].setDarkestSecret(input);
            break ;
        }
    }
    this->_index++;
    std::cout << "New contact successfully added!" << std::endl;
}

void	PhoneBook::searchContact()
{
    int i = 1;
    displayContact();
    while (i <= PHONEBOOK_SIZE)
    {
        std::cout << "Please enter contact index (from 1 to ";
        std::cout << PHONEBOOK_SIZE << ") or 0 for return: ";
        std::cin >> i;
        if (std::cin.fail() || i < 0 || i > PHONEBOOK_SIZE)
        {
            std::cout << "Error: invalid index." << std::endl;
            std::cin.clear();
            break ;
        }
        else if (i == 0)
            break ;
        else if (i > this->_index)
            std::cout << "Sorry! No contact for this index." << std::endl;
        else if (i <= this->_index)
        {
            std::cout << "******** CONTACT '" << i << "' ********" << std::endl;
            std::cout << "First name: " << contacts[i-1].getFirstName() << std::endl;
            std::cout << "Last name: " << contacts[i-1].getLastName() << std::endl;
            std::cout << "Nickname: " << contacts[i-1].getNickname() << std::endl;
            std::cout << "Phone number: " << contacts[i-1].getPhoneNumber() << std::endl;
            std::cout << "Darkest secret: " << contacts[i-1].getDarkestSecret() << std::endl;
            std::cout << "*****************************" << std::endl;
        }
    }
    std::cin.ignore(32767, '\n');
}
