#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
	std::cout << "Cat default constructor called\t\t";
	std::cout << this << std::endl;
	_b = new Brain();
}

Cat::Cat(const Cat &copy)
{
	this->_type = copy._type;
	std::cout << "Cat copy constructor called\t\t";
	std::cout << this << std::endl;
	this->_b = new Brain();
	*(this->_b) = *(copy._b);
}

Cat::~Cat()
{
	delete _b;
	std::cout << "Cat destructor called\t\t\t";
	std::cout << this << std::endl;
}

Cat & Cat::operator=(const Cat &assign)
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

Brain * Cat::getBrain() const
{
	return (_b);
}

void	Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
