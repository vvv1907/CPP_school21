#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal default constructor called\t";
	std::cout << this << std::endl;
}

AAnimal::AAnimal(std::string type)
{
	this->_type = type;
	std::cout << "AAnimal field constructor called\t";
	std::cout << this << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	this->_type = copy._type;
	std::cout << "AAnimal copy constructor called\t";
	std::cout << this << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called\t\t";
	std::cout << this << std::endl;
}

AAnimal & AAnimal::operator=(const AAnimal &assign)
{
	if (this != &assign)
		this->_type = assign._type;
	return *this;
}

std::string	AAnimal::getType() const
{
	return _type;
}
