#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; ++i)
		this->_ideas[i] = "no idea";
	std::cout << "Brain default constructor called\t";
	std::cout << this << std::endl;
}

Brain::Brain(std::string idea)
{
	for (int i = 0; i < 100; ++i)
		this->_ideas[i] = idea;
	std::cout << "Brain field constructor called\t\t";
	std::cout << this << std::endl;
}

Brain::Brain(const Brain &copy)
{
	for (int i = 0; i < 100; ++i)
		this->_ideas[i] = copy._ideas[i];
	std::cout << "Brain copy constructor called\t\t";
	std::cout << this << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\t\t\t";
	std::cout << this << std::endl;
}

Brain & Brain::operator=(const Brain &assign)
{
	if (this != &assign)
	{
		for (int i = 0; i < 100; ++i)
			this->_ideas[i] = assign._ideas[i];
	}
	return *this;
}

std::string	Brain::getIdea(int number) const
{
	if (number >=0 && number <= 99)
		return _ideas[number];
	else
		return "I don't know anything about this idea!";
}

void	Brain::setIdea(int number, std::string idea)
{
	if (number >=0 && number <= 99)
		_ideas[number] = idea;
	else
		std::cout << "Error! Try another ideas number." << std::endl;
}
