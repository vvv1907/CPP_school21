#include <cstdint>
#include <iostream>
#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

void printData(Data* data)
{
	std::cout << "address:\t" << data << std::endl;
	std::cout << "int:\t\t" << data->i << std::endl;
	std::cout << "char:\t\t" << data->c << std::endl;
	std::cout << "unsigned:\t" << data->u << std::endl;
	std::cout << "long:\t\t" << data->l << std::endl << std::endl;
}

int	main(void)
{
	Data		data;
	Data*		check;
	uintptr_t	tmp = 0;

	data.i = 2147483647;
	data.c = 'c';
	data.u = 4294967295;
	data.l = 9223372036854775807;

	std::cout << "*** struct Data after initialization:" << std::endl;
	printData(&data);

	std::cout << "*** uintptr_t before serialize:" << std::endl;	
	std::cout << "tmp address:\t" << &tmp << std::endl;
	std::cout << "tmp:\t\t" << tmp << std::endl << std::endl;

	tmp = serialize(&data);
	
	std::cout << "*** uintptr_t after serialize:" << std::endl;	
	std::cout << "tmp address:\t" << &tmp << std::endl;
	std::cout << "tmp:\t\t" << tmp << std::endl << std::endl;

	check = deserialize(tmp);

	std::cout << "*** struct Data after deserialize:" << std::endl;
	printData(check);

	return 0;
}
