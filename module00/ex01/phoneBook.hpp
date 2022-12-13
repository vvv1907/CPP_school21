#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include <string>
# include <iomanip>
# include <iostream>
# include "contact.hpp"

# define PHONEBOOK_SIZE 8

class PhoneBook
{
private:	
    Contact contacts[8];

    int     _index;
	void    displayContact();
    void    printSubstr(std::string str);
    bool    strIsspace(std::string str);

public:
    PhoneBook();
    ~PhoneBook();

    void	addContact();
    void	searchContact();
};

#endif
