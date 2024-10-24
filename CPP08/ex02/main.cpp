#include "MutantStack.hpp"
#include <iostream>
#include <iterator>
#include <list>
#include <string>

int main()
{
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
		MutantStack<int>::iterator const constIt = mstack.begin();
		if (constIt == it)
			std::cout << "congrats!!!" << std::endl;
		std::stack<int> s(mstack);
	}
	{
		std::cout << " ------------------------- LIST  --------------------" << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout <<"List : " << mstack.back() << std::endl;
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
	{
		std::cout << "------- Mutant stack with string-------------" << std::endl;
		MutantStack<std::string> tab ;
		tab.push("test!");
		tab.push("try");
		std::cout << tab.top() << std::endl;
		tab.pop();
		tab.push("test!");
		tab.push("Hello!");
		tab.push("test2!");
		tab.push("I don't know");
		std::cout << tab.size() << std::endl;
		MutantStack<std::string>::iterator it = tab.begin();
		MutantStack<std::string>::iterator ite = tab.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return 0;
}
