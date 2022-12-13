#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
        : _name (name), _weapon (weapon)
{
	_name = name;
	_weapon = weapon;
}

HumanA::~HumanA() {}

void    HumanA::attack()
{
    std::cout << this->_name << " attacks with their ";
    std::cout << this->_weapon.getType() << std::endl;
}
