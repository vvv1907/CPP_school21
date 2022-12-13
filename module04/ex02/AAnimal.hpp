#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
protected:
	std::string		_type;
public:
	AAnimal();
	AAnimal(std::string type);
	AAnimal(const AAnimal &copy);

	virtual			~AAnimal();

	AAnimal &		operator=(const AAnimal &assign);
	
	std::string		getType() const;

	virtual void	makeSound() const = 0;
};

#endif
