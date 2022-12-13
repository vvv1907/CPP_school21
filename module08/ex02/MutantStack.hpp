#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <list>

template <typename T>
class MutantStack: public std::stack<T>
{
public:
	MutantStack(): std::stack<T>() {};
	MutantStack(const MutantStack &copy): std::stack<T>(copy) {};
	MutantStack & operator=(const MutantStack &assign)
	{
		if (this != &assign)
			std::stack<T>::operator=(assign);
		return *this;
	};
	~MutantStack(){};

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

#endif
