# include "MutantStack.hpp"
# include <iostream>
# include <list>
# include <string>

int main()
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

	std::cout <<"\n";

	std::list<int> mylist;
	mylist.push_back(5);
	mylist.push_back(17);
	std::cout << mylist.back() << std::endl;
	mylist.pop_back();
	std::cout << mylist.size() << std::endl;
	mylist.push_back(3);
	mylist.push_back(5);
	mylist.push_back(737);
	
	mylist.push_back(0);
	std::list<int>::iterator it_list = mylist.begin();
	std::list<int>::iterator ite_list = mylist.end();
	++it_list;
	--it_list;
	while (it_list != ite_list)
	{
		std::cout << *it_list << std::endl;
		++it_list;
	}

	MutantStack<std::string> mystrings;
	mystrings.push("Hello");
	mystrings.push("World");
	mystrings.push("This");
	mystrings.push("is");
	mystrings.push("cs50");

	MutantStack<std::string>::reverse_iterator it_strings = mystrings.rbegin();
	MutantStack<std::string>::reverse_iterator ite_strings = mystrings.rend();
	std::cout << "\n";
	while (it_strings != ite_strings)
	{
		std::cout << *it_strings;
		++it_strings;
		if (it_strings != ite_strings)
			std::cout << " ";
	}
}