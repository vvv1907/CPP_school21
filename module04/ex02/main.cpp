#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main(void)
{
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "*** Constructors check ***" << std::endl << std::endl;
	// AAnimal test1;
	// AAnimal *test2 = new Animal();
	Cat first;
	AAnimal *second = new Dog(); 

	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "*** Methods check ***" << std::endl << std::endl;
	std::cout << first.getType() << std::endl;
	first.makeSound();
	std::cout << second->getType() << std::endl;
	second->makeSound();
	
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "*** Destructors check ***" << std::endl << std::endl;
	delete second;

	return 0;
}
