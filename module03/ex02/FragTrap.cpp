#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Default Constructor called of FragTrap " << _name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Fields Constructor called of FragTrap " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	_hitPoints = copy.getHitPoints();
	_energyPoints = copy.getEnergyPoints();
	_attackDamage = copy.getAttackDamage();
	std::cout << "Copy Constructor called of FragTrap " << _name << std::endl;
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "Destructor called of FragTrap " << _name << std::endl;
}

// Operators
FragTrap & FragTrap::operator=(const FragTrap &assign)
{
	if (this != &assign)
	{
		_name = assign.getName();
		_hitPoints = assign.getHitPoints();
		_energyPoints = assign.getEnergyPoints();
		_attackDamage = assign.getAttackDamage();
	}
	return *this;
}

void FragTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
		std::cout << "FragTrap " << _name << " dead" << std::endl;
	else if (_energyPoints <= 0)
		std::cout << "FragTrap " << _name << ": not enough energy" << std::endl;
	else
	{
		_energyPoints--;
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing ";
		std::cout << _attackDamage << " points of damage!" << std::endl;
	}
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << ": High Five, Guy!" << std::endl;
}
