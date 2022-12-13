#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called\t";
	std::cout <<  this << std::endl;
}

Animal::Animal(std::string type)
{
	this->_type = type;
	std::cout << "Animal field constructor called\t\t";
	std::cout <<  this << std::endl;
}

Animal::Animal(const Animal &copy)
{
	this->_type = copy._type;
	std::cout << "Animal copy constructor called\t\t";
	std::cout <<  this << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called\t\t";
	std::cout <<  this << std::endl;
}

Animal & Animal::operator=(const Animal &assign)
{
	if (this != &assign)
		this->_type = assign._type;
	return *this;
}

std::string	Animal::getType() const
{
	return _type;
}

void	Animal::makeSound() const
{
	std::cout << "??? some unknown sound ???" << std::endl;
}
