#include "easyfind.hpp"

void print(const int& n)
{
	std::cout << " " << n;
}

int main()
{
	std::vector<int> vec;
	std::vector<int>::iterator iterVec;
	std::deque<int> deq;
	std::deque<int>::iterator iterDeq;
	std::list<int> lst;
	std::list<int>::iterator iterLst;

	for (int i = 0; i < 42; i++)
	{
		vec.push_back(i);
		deq.push_front(i * 3);
	}

	std::cout << std::endl << " *** our vector:" << std::endl;
	std::for_each(vec.begin(), vec.end(), print);
	std::cout << std::endl;
	std::cout << std::endl << " *** our deque:" << std::endl;
	std::for_each(deq.begin(), deq.end(), print);
	std::cout << std::endl;
	std::cout << std::endl << " *** our list:" << std::endl;
	std::for_each(lst.begin(), lst.end(), print);
	std::cout << std::endl;
	
	std::cout << std::endl << " *** try to find '42' in vector:" << std::endl;
	try
	{
		iterVec = easyfind(vec, 42);
		std::cout << " " << *iterVec << " is found!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << " *** try to find '21' in deque:" << std::endl;
	try
	{
		iterDeq = easyfind(deq, 21);
		std::cout << " " << *iterDeq << " is found!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << " *** try to find '0' in list:" << std::endl;
	try
	{
		iterLst = easyfind(lst, 0);
		std::cout << " " << *iterLst << " is found!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}
