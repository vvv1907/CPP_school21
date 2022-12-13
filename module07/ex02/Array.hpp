#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
private:
	T * 			_array;
	unsigned int	_size;

public:
	class OutOfBounds : public std::exception 
	{
	public:
		const char* what() const throw()
		{
			return "Out of bounds!";
		};
	};

	Array();
	Array(const unsigned int & n);
	Array(const Array & copy);

	~Array();

	unsigned int size() const;

	Array & operator=(const Array & assign);
	T & operator[](const unsigned int index);
	const T & operator[](const unsigned int index) const;
};

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(const unsigned int & n)
{
	_size = n;
	_array = new T[n]();
}

template <typename T>
Array<T>::Array(const Array & copy)
{
	this->_size = copy._size;
	this->_array = new T[copy._size]();
	for (unsigned int i = 0; i < copy._size; i++)
		this->_array[i] = copy._array[i];
}

template <typename T>
Array<T>::~Array()
{
	if (_size != 0)
	{
		delete[] _array;
		_array = NULL;
		_size = 0;
	}
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return _size;
}

template <typename T>
Array<T> & Array<T>::operator=(const Array & assign)
{
	if (this != &assign)
	{
		if (this->_size != 0)
		{
			delete[] this->_array;
			this->_array = NULL;
			this->_size = 0;
		}
		this->_size = assign._size;
		this->_array = new T[assign._size]();
		for (unsigned int i = 0; i < assign._size; i++)
			this->_array[i] = assign._array[i];
	}
	return *this;
}

template <typename T>
T & Array<T>::operator[](const unsigned int index)
{
	if (index >= _size || !_array)
		throw Array<T>::OutOfBounds();
	else
		return _array[index];
}

template <typename T>
const T & Array<T>::operator[](const unsigned int index) const
{
	if (index >= _size || !_array)
		throw Array<T>::OutOfBounds();
	else
		return _array[index];
}

#endif
