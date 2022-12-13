#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain* _b;
public:
	Cat();
	Cat(const Cat &copy);

	virtual	~Cat();

	Cat &	operator=(const Cat &assign);
	
	Brain * getBrain() const;

	void	makeSound() const;
};

#endif
