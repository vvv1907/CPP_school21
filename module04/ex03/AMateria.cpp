#include "AMateria.hpp"

AMateria::AMateria()
{
	this->_type = "AMateria";
	std::cout << "AMateria default constructor called\t\t";
	std::cout << this << std::endl;
}

AMateria::AMateria(std::string const &type)
{
	this->_type = type;
	std::cout << "AMateria field constructor called\t\t";
	std::cout << this << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
	this->_type = copy._type;
	std::cout << "AMateria copy constructor called\t\t";
	std::cout << this << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called\t\t\t";
	std::cout << this << std::endl;
}

AMateria &	AMateria::operator=(const AMateria &assign)
{
	if (this != &assign)
		this->_type = assign._type;
	return *this;
}

std::string const & AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << target.getName() << std::endl;
}
