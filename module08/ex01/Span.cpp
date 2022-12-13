#include "Span.hpp"

const char* Span::ArrayIsFull::what() const throw()
{
	return "Error: the array already contains the maximum number of elements!";
}

const char* Span::ArrayIsEmpty::what() const throw()
{
	return "Error: the array contains too few elements!";
}

Span::Span() : _array(0, 0) 
{
	_array.reserve(0);
}

Span::Span(const unsigned int & n) : _array(0, 0) 
{
	_array.reserve(n);
}

Span::Span(const Span & copy)
{
	this->_array.reserve(copy._array.capacity());
	std::copy(copy._array.begin(), copy._array.end(), _array.begin());
}

Span::~Span() {}

Span & Span::operator=(const Span & assign)
{
	if (this != &assign)
	{
		_array.clear();
		this->_array.reserve(assign._array.capacity());
		std::copy(assign._array.begin(), assign._array.end(), _array.begin());
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (_array.capacity() <= _array.size())
		throw Span::ArrayIsFull();
	_array.push_back(number);
}

int	Span::shortestSpan()
{
	if (_array.size() < 2)
		throw Span::ArrayIsEmpty();
	
	std::vector<int> tmp(_array);
	int	min;
	int	value;
	std::vector<int>::iterator iter;

	std::sort(tmp.begin(), tmp.end());
	min = std::numeric_limits<int>::max();
	for (iter = (tmp.begin() + 1); iter != tmp.end(); iter++)
	{
		value = std::abs(*(iter) - *(iter - 1));
		if (value < min)
			min = value;
	}
	return (min);
}

int	Span::longestSpan()
{
	if (_array.size() < 2)
		throw Span::ArrayIsEmpty();
	
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> iter;
	iter = std::minmax_element(_array.begin(), _array.end());
	return (*iter.second - *iter.first);
}

void Span::printArray()
{
	std::vector<int>::iterator iter;
	for (iter = _array.begin(); iter != _array.end(); iter++)
		std::cout << *iter << std::endl;
}
