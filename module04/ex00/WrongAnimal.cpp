#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called\t";
	std::cout <<  this << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << "WrongAnimal field constructor called\t";
	std::cout <<  this << std::endl;
	this->_type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal copy constructor called\t";
	std::cout <<  this << std::endl;
	this->_type = copy._type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called\t\t";
	std::cout <<  this << std::endl;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal &assign)
{
	if (this != &assign)
		this->_type = assign._type;
	return *this;
}

std::string	WrongAnimal::getType() const
{
	return _type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Wrong sound!" << std::endl;
}
