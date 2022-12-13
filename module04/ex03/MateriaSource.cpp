#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < SSIZE; i++)
		_store[i] = NULL;
	std::cout << "MateriaSource default constructor called\t";
	std::cout << this << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (int i = 0; i < SSIZE; i++)
	{
		if (_store[i])
			delete this->_store[i];
		if (copy._store[i])
			this->_store[i] = copy._store[i]->clone();
	}
	std::cout << "MateriaSource copy constructor called\t";
	std::cout << this << std::endl;
}
	
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < SSIZE; i++)
	{
		if (_store[i])
			delete _store[i];
		_store[i] = NULL;
	}
	std::cout << "MateriaSource destructor called\t\t\t";
	std::cout << this << std::endl;
}

MateriaSource &	MateriaSource::operator=(const MateriaSource &assign)
{
	if (this != &assign)
	{
		for (int i = 0; i < SSIZE; i++)
		{
			if (_store[i])
				delete _store[i];
			if (assign._store[i])
				this->_store[i] = assign._store[i]->clone();
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* input)
{
	if (!input)
		return ;
	for (int i = 0; i < SSIZE; i++)
	{
		if (!_store[i])
		{
			_store[i] = input;
			std::cout << "Materia " << input->getType() << " stored" << std::endl;
			return ;
		}
	}
	std::cout << "Not enough place in storage to learn " << input->getType() << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < SSIZE; i++)
	{
		if (_store[i] && _store[i]->getType() == type)
		{
			std::cout << "Creating materia " << type << std::endl;
			return _store[i]->clone();
		}
	}
	std::cout << "Fail to create materia" << std::endl;
	return NULL;
}
