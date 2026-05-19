#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack &other);
		~MutantStack(void);
		MutantStack &operator=(const MutantStack & other);

		typedef typename std::stack<T>::container_type container;

		typedef typename container::iterator iterator;
		typedef typename container::const_iterator const_iterator;
		typedef typename container::reverse_iterator reverse_iterator;
		typedef typename container::const_reverse_iterator const_reverse_iterator;

		iterator begin();
		iterator end();

		const_iterator cbegin() const;
		const_iterator cend() const;

		reverse_iterator rbegin();
		reverse_iterator rend();

		const_reverse_iterator crbegin() const;
		const_reverse_iterator crend() const;
};

# include "MutantStack.tpp"

#endif
