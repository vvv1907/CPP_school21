#include "convert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: wrong number of arguments!" << std::endl;
		return 1;
	}
	else
		std::cout << Convert(argv[1]);
	return 0;
}
