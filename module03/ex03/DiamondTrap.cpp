#include "DiamondTrap.hpp"

// Constructors
DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
	ClapTrap::_name = "noname_clap_name";
	this->_name = "noname";
	this->_hitPoints = FragTrap::getHitPoints();
	this->_energyPoints = ScavTrap::getEnergyPoints();
	this->_attackDamage = FragTrap::getAttackDamage();
	std::cout << "Default Constructor called of DiamondTrap " << _name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name)
{
	ClapTrap::_name = name + "_clap_name";
	this->_name = name;
	this->_hitPoints = FragTrap::getHitPoints();
	this->_energyPoints = ScavTrap::getEnergyPoints();
	this->_attackDamage = FragTrap::getAttackDamage();
	std::cout << "Field Constructor called of DiamondTrap " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ScavTrap(copy), FragTrap(copy)
{
	ClapTrap::_name = copy.ClapTrap::_name;
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
	std::cout << "Copy Constructor called of DiamondTrap " << _name << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor called of DiamondTrap " << _name << std::endl;
}

// Operator
DiamondTrap & DiamondTrap::operator=(const DiamondTrap &assign)
{
	if (this != &assign)
	{
		ClapTrap::_name = assign.ClapTrap::_name;
		_name = assign.getName();
		_hitPoints = assign.getHitPoints();
		_energyPoints = assign.getEnergyPoints();
		_attackDamage = assign.getAttackDamage();
	}
	return *this;
}

// functions for more realistic DiamondTrap
void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name: " << _name << ". My ClapTrap name: ";
	std::cout << ClapTrap::_name << std::endl;
}
