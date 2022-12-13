#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called\t\t";
	std::cout <<  this << std::endl;
}

Cat::Cat(const Cat &copy)
{
	this->_type = copy._type;
	std::cout << "Cat copy constructor called\t\t";
	std::cout <<  this << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\t\t\t";
	std::cout <<  this << std::endl;
}

Cat & Cat::operator=(const Cat &assign)
{
	if (this != &assign)
		this->_type = assign._type;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
