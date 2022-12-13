#include <string>
#include <iostream>
#include "Zombie.hpp"

int main(void)
{
    std::cout << "Hi! Please, enter a positive integer - size of Horde: ";
	int hordeSize;
	std::cin >> hordeSize;
    std::cout << "Next enter a string - name of Zombie: ";
    std::string name;
	std::cin >> name;
    std::cout << "Creating Horde of Zombie:" << std::endl;
    Zombie *horde = zombieHorde(hordeSize, name);
    if (!horde)
        return (1);
    for (int i = 0; i < hordeSize; i++)
        horde[i].announce();
	delete[] (horde);
	return (0);
}
