#include "MutantStack.hpp"

void subjCheck()
{
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void listCheck()
{
		std::list<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << mstack.back() << std::endl;

		mstack.pop_back();

		std::cout << mstack.size() << std::endl;

		mstack.push_back(3); 
		mstack.push_back(5); 
		mstack.push_back(737); 
		mstack.push_back(0);

		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite) 
		{
			std::cout << *it << std::endl;
			++it; 
		}
}

void doubleCheck()
{
		MutantStack<double> mstack;

		mstack.push(5.0);
		mstack.push(17.0);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3.0); 
		mstack.push(5.0); 
		mstack.push(737.0); 
		mstack.push(0.0);

		MutantStack<double>::iterator it = mstack.begin();
		MutantStack<double>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite) 
		{
			std::cout << *it << std::endl;
			++it; 
		}
}

void charCheck()
{
	MutantStack<char> mstack;
	mstack.push('a');
	mstack.push('b');
	mstack.push('c');
	mstack.push('d');
	mstack.push('e');
	// mstack.pop();
	MutantStack<char>::iterator it = mstack.begin();
	MutantStack<char>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void stringCheck()
{
		MutantStack<std::string> mstack;
		mstack.push("Hello, ");
		mstack.push("world");
		mstack.push("!");
		mstack.push("21");
		mstack.push("42");
		// mstack.pop();
		// mstack.pop();
		MutantStack<std::string>::iterator it = mstack.begin();
		MutantStack<std::string>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) 
		{
			std::cout << *it << std::endl;
			++it;
		}
}

int main()
{
	std::cout << "\t*** subj check:" << std::endl;
	subjCheck();
	std::cout << "\t*** list check:" << std::endl;
	listCheck();
	std::cout << "\t*** double check:" << std::endl;
	doubleCheck();
	std::cout << "\t*** char check:" << std::endl;
	charCheck();
	std::cout << "\t*** string check:" << std::endl;
	stringCheck();

	return 0;
}
