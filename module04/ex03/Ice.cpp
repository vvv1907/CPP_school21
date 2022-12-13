#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout << "Ice default constructor called\t\t\t";
	std::cout << this << std::endl;
}

Ice::Ice(const Ice &copy)
{
	this->_type = copy._type;
	std::cout << "Ice copy constructor called\t\t\t";
	std::cout << this << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called\t\t\t\t";
	std::cout << this << std::endl;
}

Ice &	Ice::operator=(const Ice &assign)
{
	if (this != &assign)
		this->_type = assign._type;
	return *this;
}

AMateria* Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName();
	std::cout << " *" << std::endl;
}
