#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << "Cure default constructor called\t\t\t";
	std::cout << this << std::endl;
}

Cure::Cure(const Cure &copy)
{
	this->_type = copy._type;
	std::cout << "Cure copy constructor called\t\t\t";
	std::cout << this << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called\t\t\t\t";
	std::cout << this << std::endl;
}

Cure &	Cure::operator=(const Cure &assign)
{
	if (this != &assign)
		this->_type = assign._type;
	return *this;
}

AMateria* Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName();
	std::cout << "'s wounds *" << std::endl;
}
