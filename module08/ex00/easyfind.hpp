#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <vector>
# include <deque>
# include <list>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator iter;
	iter = std::find(container.begin(), container.end(), value);
	if (container.begin() == container.end())
		throw std::out_of_range(" Error: container is empty!");
	if (iter == container.end())
		throw std::out_of_range(" Error: value not found!");
	return (iter);
}

#endif
