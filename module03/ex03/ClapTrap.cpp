#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap() 
{
	_name = "noname";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "Default Constructor called of ClapTrap " << _name << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "Fields Constructor called of ClapTrap " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	_name = copy.getName();
	_hitPoints = copy.getHitPoints();
	_energyPoints = copy.getEnergyPoints();
	_attackDamage = copy.getAttackDamage();
	std::cout << "Copy Constructor called of ClapTrap " << _name << std::endl;
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called of ClapTrap " << _name << std::endl;
}

// Operator
ClapTrap & ClapTrap::operator=(const ClapTrap &assign)
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

// Getters / Setters
std::string ClapTrap::getName() const
{
	return _name;
}

void ClapTrap::setName(std::string name)
{
	_name = name;
}

int ClapTrap::getHitPoints() const
{
	return _hitPoints;
}

void ClapTrap::setHitPoints(int hitPoints)
{
	_hitPoints = hitPoints;
	std::cout << "ClapTrap " << _name << " set " << hitPoints;
	std::cout << " hit points" << std::endl;
}

int ClapTrap::getEnergyPoints() const
{
	return _energyPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
	_energyPoints = energyPoints;
	std::cout << "ClapTrap " << _name << " set " << energyPoints;
	std::cout << " energy points" << std::endl;
}

int ClapTrap::getAttackDamage() const
{
	return _attackDamage;
}

void ClapTrap::setAttackDamage(int attackDamage)
{
	_attackDamage = attackDamage;
	std::cout << "ClapTrap " << _name << " set " << attackDamage;
	std::cout << " attack damage" << std::endl;
}

// functions for more realistic ClapTrap
void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " dead" << std::endl;
	else if (_energyPoints <= 0)
		std::cout << "ClapTrap " << _name << ": not enough energy" << std::endl;
	else
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing ";
		std::cout << _attackDamage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " dead" << std::endl;
	else
	{
		_hitPoints -= amount;
		if (_hitPoints <= 0) 
		{
			_hitPoints = 0;
			std::cout << "ClapTrap " << _name << " got killed :(" << std::endl;
		}
		else
		{
			std::cout << "ClapTrap " << _name << " got " << amount;
			std::cout << " damage" << std::endl;
		}
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " dead" << std::endl;
	else if (_energyPoints <= 0)
		std::cout << "ClapTrap " << _name << ": not enough energy" << std::endl;
	else
	{
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " got " << amount;
		std::cout << " repaired" << std::endl;
	}
}

void ClapTrap::getInfo()
{
	std::cout << "[INFO] " << getName() << "\tHit Points: " << getHitPoints();
	std::cout << "\tEnergy Points: " << getEnergyPoints();
	std::cout << "\tAttack Damage: " << getAttackDamage() << std::endl;
}
