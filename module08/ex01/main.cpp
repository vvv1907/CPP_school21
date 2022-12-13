#include "Span.hpp"

int main() 
{
	std::cout << std::endl << "test from subject: " << std::endl;
	std::cout << "**********************************************" << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.printArray();

	std::cout << "shortest span = " << sp.shortestSpan() << std::endl;
	std::cout << "longest span = " << sp.longestSpan() << std::endl;

	std::cout << std::endl << "test for 10 000 elements of array: " << std::endl;
	std::cout << "**********************************************" << std::endl;

	Span spBig = Span(10000);

	for (int i = -5000; i <= 4999; i++)
		spBig.addNumber(i);
	std::cout << "shortest span = " << spBig.shortestSpan() << std::endl;
	std::cout << "longest span = " << spBig.longestSpan() << std::endl;

	std::cout << std::endl << "test for 100 000 elements of array: " << std::endl;
	std::cout << "**********************************************" << std::endl;

	std::vector<int> vector;
	Span spVeryBig = Span(100000);
	
	for (int i = -50000; i <= 49999; i++)
		vector.push_back(i);
	spVeryBig.addManyNumbers(std::begin(vector), std::end(vector));
	std::cout << "shortest span = " << spVeryBig.shortestSpan() << std::endl;
	std::cout << "longest span = " << spVeryBig.longestSpan() << std::endl;

	std::cout << std::endl << "test for exceptions: " << std::endl;
	std::cout << "**********************************************";
	std::cout << std::endl << "add first number to array of 3 elements" << std::endl;
	Span check (3);
	check.addNumber(0);
	check.printArray();
	std::cout << std::endl << "try to find shortest span in our array: " << std::endl;
	try 
	{
		std::cout << "shortest span = "  << check.shortestSpan() << std::endl;
	} 
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "add second number to array of 3 elements" << std::endl;
	check.addNumber(21);
	check.printArray();
	try 
	{
		std::cout << "shortest span = "  << check.shortestSpan() << std::endl;
		std::cout << "longest span = " << check.longestSpan() << std::endl;
	} 
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "add third number to array of 3 elements" << std::endl;
	check.addNumber(42);
	check.printArray();
	try 
	{
		std::cout << "shortest span = "  << check.shortestSpan() << std::endl;
		std::cout << "longest span = " << check.longestSpan() << std::endl;
	} 
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "try to add fourth number in our array:" << std::endl;
	try 
	{
		check.addNumber(99);
	} 
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
