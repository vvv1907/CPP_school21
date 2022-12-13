#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Default Constructor called of ScavTrap " << _name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Fields Constructor called of ScavTrap " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	_hitPoints = copy.getHitPoints();
	_energyPoints = copy.getEnergyPoints();
	_attackDamage = copy.getAttackDamage();
	std::cout << "Copy Constructor called of ScavTrap " << _name << std::endl;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called of ScavTrap " << _name << std::endl;
}

// Operators
ScavTrap & ScavTrap::operator=(const ScavTrap &assign)
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

void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
		std::cout << "ScavTrap " << _name << " dead" << std::endl;
	else if (_energyPoints <= 0)
		std::cout << "ScavTrap " << _name << ": not enough energy" << std::endl;
	else
	{
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing ";
		std::cout << _attackDamage << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}
