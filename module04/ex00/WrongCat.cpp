#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called\t";
	std::cout <<  this << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "WrongCat copy constructor called\t";
	std::cout <<  this << std::endl;
	this->_type = copy._type;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\t\t";
	std::cout <<  this << std::endl;
}

WrongCat & WrongCat::operator=(const WrongCat &assign)
{
	if (this != &assign)
		this->_type = assign._type;
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong meow!" << std::endl;
}
