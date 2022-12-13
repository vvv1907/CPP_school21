#include <string>
#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	std::cout << "Creating class instance Zombie:" << std::endl;
	Zombie firstZombie("First");
	firstZombie.announce();
	std::cout << "Creating Zombie on the heap:" << std::endl;
	Zombie *secondZombie = newZombie("Second");
	if (!secondZombie)
		return (1);
	secondZombie->announce();
	std::cout << "Creating Zombie on the stack:" << std::endl;
	randomChump("Third");
	delete secondZombie;
	return (0);
}
