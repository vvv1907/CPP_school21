#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-";
    std::cout << "pickle-special-ketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. ";
    std::cout << "You didn't put enough bacon in my burger! If you did, ";
    std::cout << "I wouldn't be asking for more!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. ";
    std::cout << "I've been coming for years whereas you started working ";
    std::cout << "here since last month." << std::endl;
	std::cout << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now.";
    std::cout << std::endl << std::endl;
}

void    Harl::complain(std::string level)
{
	void    (Harl::*action[4])(void) = 
    {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

	std::string message[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
    bool flag = true;

    for (int i = 0; i < 4; i++)
    {
		if (level == (message[i]))
        {
			(this->*action[i])();
            flag = false;
        }
	}
    if (flag)
    {
        std::cout << "Wrong message! Probably ";
        std::cout << "complaining about insignificant problems." << std::endl;
    }
}
