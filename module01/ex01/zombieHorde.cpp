#include "Zombie.hpp"

Zombie  *zombieHorde(int N, std::string name)
{   
    if (N < 1)
    {
        std::cout << "Error: invalid size of Horde!" << std::endl;
        return (NULL);
    }
    
    Zombie *zombieHorde = new (std::nothrow) Zombie[N];
    if (!zombieHorde)
    {
        std::cout << "Error: could not allocate memory!" << std::endl;
        return (NULL); 
    }
    for (int i = 0; i < N; i++)
        zombieHorde[i].setName(name);
    
    return (zombieHorde);
}
