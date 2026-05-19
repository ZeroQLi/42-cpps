#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <algorithm>

class Span
{
	private:
		unsigned int		s;
		std::vector<int>	arr;

	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span& other);
		Span &operator=(const Span &other);
		~Span();

		void	addNumber(int n);
		void	addNumber(const std::vector<int>::iterator& it1, const std::vector<int>::iterator& it2);

		int		shortestSpan();
		int		longestSpan();

		class OverflowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class InvalidAmountException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif

