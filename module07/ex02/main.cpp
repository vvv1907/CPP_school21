#include "Array.hpp"

#define MAX_VAL 9

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    
	std::cout << std::endl << "content of arrays after creation: " << std::endl;
	std::cout << "**********************************************" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << "numbers[" << i << "] = " << numbers[i];
        std::cout << "\t\tmirror[" << i << "] = " << mirror[i];
		std::cout << std::endl;
    }
	std::cout << "**********************************************" << std::endl;
	
	for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand() % 10000;
        numbers[i] = value;
        mirror[i] = value;
    }

	std::cout << std::endl << "content of arrays after initialization: " << std::endl;
	std::cout << "**********************************************" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << "numbers[" << i << "] = " << numbers[i];
        std::cout << "\tmirror[" << i << "] = " << mirror[i];
		std::cout << std::endl;
    }
	std::cout << "**********************************************" << std::endl;

    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);

		std::cout << std::endl << "content of arrays after copy: " << std::endl;
		std::cout << "**********************************************" << std::endl;
		for (int i = 0; i < MAX_VAL; i++)
		{
			std::cout << "numbers[" << i << "] = " << numbers[i];
			std::cout << "\ttest[" << i << "] = " << test[i];
			std::cout << std::endl;
		}
		std::cout << "**********************************************" << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
	
	std::cout << std::endl << "try to access element out of bounds:" << std::endl;
	std::cout << "**********************************************" << std::endl;
	try
    {
		std::cout << "numbers[-2] = " << numbers[-2] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
		std::cout << "numbers[9] = " << numbers[MAX_VAL] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
	std::cout << "**********************************************" << std::endl;

	std::cout << std::endl << "try to access element of empty array:" << std::endl;
	std::cout << "**********************************************" << std::endl;
    try
    {
        Array<int> e_array;
		std::cout << "e_array[0] = " << e_array[0] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
	std::cout << "**********************************************" << std::endl;

	std::cout << std::endl << "try to access element of const array:" << std::endl;
	std::cout << "**********************************************" << std::endl;
    try
    {
        const Array<int> c_array(2);
		std::cout << "c_array[1] = " << c_array[1] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
	std::cout << "**********************************************" << std::endl;

    delete [] mirror;

    return 0;
}
