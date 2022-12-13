#include "Point.hpp"

void printPointCoordinates(Point const a, char name)
{
	std::cout << name << "(" << a.getX() << ", " << a.getY() << ")";
}

int	main( void ) 
{
	Point	a, b(10, 10), c(20, 0);
	Point	in(2, 1);
	Point	out(20, 20);
	Point	edge(3, 3);
	Point	vertex(10, 10);
	
	std::cout << std::boolalpha;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Given a triangle with the following vertices:" << std::endl;
	printPointCoordinates(a, 'A');
	printPointCoordinates(b, 'B');
	printPointCoordinates(c, 'C');
	std::cout << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "The point ";
	printPointCoordinates(in, 'I');
	std::cout << "\t is inside triangle?\t" << bsp(a, b, c, in) << std::endl;
	std::cout << "The point ";
	printPointCoordinates(out, 'O');
	std::cout << "\t is inside triangle?\t" << bsp(a, b, c, out) << std::endl;
	std::cout << "The point ";
	printPointCoordinates(edge, 'E');
	std::cout << "\t is inside triangle?\t" << bsp(a, b, c, edge) << std::endl;
	std::cout << "The point ";
	printPointCoordinates(vertex, 'V');
	std::cout <<"\t is inside triangle?\t"<< bsp(a, b, c, vertex) << std::endl;
	
	return 0;
}
