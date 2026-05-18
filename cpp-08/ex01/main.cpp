# include "Span.hpp"
# include <time.h>
# include <stdlib.h>

int main(void)
{

	Span sp = Span(5);
	sp.addNumber(6);
	try
	{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(12);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Span				bigNums(100000);
	std::vector<int>	nums;
	std::srand(time(NULL));
	for (int i = 0; i < 100000; i++)
	{
		int random_int = rand() % 1000000000;
		nums.push_back(random_int);
	}
	try
	{
		bigNums.addNumber(nums.begin(), nums.end());
		std::cout << "shortest span: " << bigNums.shortestSpan() << std::endl;
		std::cout << "longest span: " << bigNums.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
