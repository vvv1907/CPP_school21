#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-";
    std::cout << "pickle-special-ketchup burger. I really do!" << std::endl;
    std::cout << std::endl;
}

void	Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. ";
    std::cout << "You didn't put enough bacon in my burger! If you did, ";
    std::cout << "I wouldn't be asking for more!" << std::endl;
    std::cout << std::endl;
}

void	Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. ";
    std::cout << "I've been coming for years whereas you started working ";
    std::cout << "here since last month." << std::endl;
    std::cout << std::endl;
}

void	Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.";
    std::cout << std::endl << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	message[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i = 0;

    while (i < 4)
		if (level == (message[++i]))
			break;
	switch (i)
	{
		case 0:
			Harl::debug();
		case 1:
			Harl::info();
		case 2:
			Harl::warning();
		case 3:
			Harl::error();
			break;
		default:
			std::cout << "[Probably complaining about insignificant problems]";
			std::cout << std::endl;
	}
}
