#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{   
    Zombie  *newZombie = new (std::nothrow) Zombie(name);
    if (!newZombie)
    {
        std::cout << "Error: could not allocate memory!" << std::endl;
        return (NULL);
    }
    
    return (newZombie);
}
