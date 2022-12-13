#include "Character.hpp"

Character::Character()
{
	this->_name = "noname";
	for (int i = 0; i < ISIZE; i++)
		_inventory[i] = NULL;
	std::cout << "Character default constructor called\t\t";
	std::cout << this << std::endl;
}

Character::Character(std::string name)
{
	this->_name = name;
	for (int i = 0; i < ISIZE; i++)
		_inventory[i] = NULL;
	std::cout << "Character field constructor called\t\t";
	std::cout << this << std::endl;
}

Character::Character(const Character &copy)
{
	this->_name = copy.getName();
	for (int i = 0; i < ISIZE; i++)
	{
		if (_inventory[i])
			delete this->_inventory[i];
		if (copy._inventory[i])
			this->_inventory[i] = copy._inventory[i]->clone();
	}
	std::cout << "Character copy constructor called\t\t";
	std::cout << this << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < ISIZE; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		_inventory[i] = NULL;
	}
	std::cout << "Character destructor called\t\t\t";
	std::cout << this << std::endl;
}

Character &	Character::operator=(const Character &assign)
{
	if (this != &assign)
	{
		this->_name = assign.getName();
		for (int i = 0; i < ISIZE; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (assign._inventory[i])
				this->_inventory[i] = assign._inventory[i]->clone();
		}
	}
	return *this;
}

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < ISIZE; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			std::cout << "Equip character " << _name << " with ";
			std::cout << m->getType() << std::endl;
			return ;
		}
	}
	std::cout << "Can't equip character " << _name << " with ";
	std::cout << m->getType() << ". Inventory full!" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < ISIZE && _inventory[idx])
	{
		std::cout << "Unequip " << this->_inventory[idx]->getType();
		std::cout << " from character " << this->getName() << std::endl;
		this->_inventory[idx] = NULL;
		return ;
	}
	std::cout << "Failed to unequip " << this->getName() << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < ISIZE && _inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << "Use function failed on character " << _name << std::endl;
}
