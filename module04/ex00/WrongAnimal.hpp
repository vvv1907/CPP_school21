#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
protected:
	std::string		_type;
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal &copy);

	virtual			~WrongAnimal();

	WrongAnimal &	operator=(const WrongAnimal &assign);
	
	std::string		getType() const;

	void			makeSound() const;
};

#endif
