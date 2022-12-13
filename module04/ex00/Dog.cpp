#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called\t\t";
	std::cout <<  this << std::endl;
}

Dog::Dog(const Dog &copy)
{
	this->_type = copy._type;
	std::cout << "Dog copy constructor called\t\t";
	std::cout <<  this << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\t\t\t";
	std::cout <<  this << std::endl;
}

Dog & Dog::operator=(const Dog &assign)
{
	if (this != &assign)
		this->_type = assign._type;
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}
