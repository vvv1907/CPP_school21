#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main(void)
{
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "*** Constructors check ***" << std::endl << std::endl;
	const Animal *j = new Dog(); 
	const Animal *i = new Cat();
	
	delete i;
	delete j;
	std::cout << std::endl;
	
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "*** Destructors check ***" << std::endl << std::endl;
	{
		Dog basic;
		std::cout << "\t### Dog 'basic' was created ###" << std::endl;
		{
			Dog tmp = basic;
			std::cout << "\t### Dog 'tmp' was created ###" << std::endl;
		}
		std::cout << "\t### Dog 'tmp' was destroyed ###" << std::endl;
	}
	std::cout << "\t### Dog 'basic' was destroyed ###" << std::endl;
	std::cout << std::endl;

	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "*** Getters and setters check ***" << std::endl << std::endl;
	Cat *firstCat = new Cat();
	std::cout << std::endl;
	Cat *secondCat = new Cat();
	std::cout << std::endl;

	std::cout << firstCat->getBrain()->getIdea(-1);
	std::cout << std::endl;
	std::cout << firstCat->getBrain()->getIdea(0);
	std::cout << std::endl;
	
	firstCat->getBrain()->setIdea(-1, "I'm hungry!");
	firstCat->getBrain()->setIdea(0, "I'm hungry!");
	std::cout << firstCat->getBrain()->getIdea(0);
	std::cout << std::endl << std::endl;

	std::cout << secondCat->getBrain()->getIdea(100);
	std::cout << std::endl;
	std::cout << secondCat->getBrain()->getIdea(99);
	std::cout << std::endl;
	
	secondCat->getBrain()->setIdea(100, "I'm very hungry!");
	secondCat->getBrain()->setIdea(99, "I'm very hungry!");
	std::cout << secondCat->getBrain()->getIdea(99);
	std::cout << std::endl << std::endl;

	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "*** Assignment and copy check ***" << std::endl << std::endl;
	Cat thirdCat(*firstCat);
	std::cout << thirdCat.getType() << std::endl;
	thirdCat.makeSound();
	std::cout << thirdCat.getBrain()->getIdea(0);
	std::cout << std::endl << std::endl;
	
	Cat fourthCat = *secondCat;
	std::cout << fourthCat.getType() << std::endl;
	fourthCat.makeSound();
	std::cout << fourthCat.getBrain()->getIdea(99);
	std::cout << std::endl << std::endl;

	delete firstCat;
	std::cout << std::endl;
	delete secondCat;
	std::cout << std::endl;

	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "*** Array of objects check ***" << std::endl << std::endl;
	Animal *array[4];
	for (int i = 0; i < 4; i++)
	{
		if (i % 2)
			array[i] = new Cat();
		else
			array[i] = new Dog();
	}
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		delete array[i];
	std::cout << std::endl;
	std::cout << "----------------------------------------------" << std::endl;

	return 0;
}
