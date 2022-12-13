#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iostream>
# include <vector>

class Span
{
private:
	std::vector<int>	_array;

public:
	class ArrayIsFull : public std::exception
	{
	public:
		const char* what() const throw();
	};
	
	class ArrayIsEmpty : public std::exception
	{
	public:
		const char* what() const throw();
	};

	Span();
	Span(const unsigned int & n);
	Span(const Span & copy);

	~Span();

	Span& operator=(const Span& assign);

	void	addNumber(int number);
	int		shortestSpan();
	int		longestSpan();
	void 	printArray();

	template <typename T>
	void	addManyNumbers(T begin, T end)
	{
		if (static_cast<int>(std::distance(begin, end)) > static_cast<int>(_array.capacity()))
			throw Span::ArrayIsFull();
		while (begin != end)
		{
			_array.push_back(*begin);
			begin++;
		}
	}

};

#endif
