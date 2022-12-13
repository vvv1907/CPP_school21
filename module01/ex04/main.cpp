#include <iostream>
#include <string>
#include <fstream>
#include "replace.hpp"

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        std::cout << "Error: invalid arguments number" << std::endl;
        return (1);
    }
    Replace	replace(argv[1], argv[2], argv[3]);
    if (!replace.replaceStr())
        return (1);
    return (0);
}
