#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
	std::cout << "Dog default constructor called\t\t";
	std::cout << this << std::endl;
	_b = new Brain();
}

Dog::Dog(const Dog &copy)
{
	this->_type = copy._type;
	std::cout << "Dog copy constructor called\t\t";
	std::cout << this << std::endl;
	this->_b = new Brain();
	*(this->_b) = *(copy._b);
}

Dog::~Dog()
{
	delete _b;
	std::cout << "Dog destructor called\t\t\t";
	std::cout << this << std::endl;
}

Dog & Dog::operator=(const Dog &assign)
{
	if (this != &assign)
	{
		this->_type = assign._type;
		if (this->_b)
			delete this->_b;
		this->_b = new Brain();
		*(this->_b) = *(assign._b);
	}
	return *this;
}

Brain * Dog::getBrain() const
{
	return (_b);
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}
