#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
private:
	Brain* _b;
public:
	Dog();
	Dog(const Dog &copy);

	virtual	~Dog();

	Dog &	operator=(const Dog &assign);
	
	Brain * getBrain() const;
	
	void	makeSound() const;
};

#endif
