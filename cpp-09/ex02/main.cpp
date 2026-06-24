#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	std::vector<int> vec;
	std::deque<int> deq;

	std::vector<Pair> mergedPairsVec;
	if (argc < 2)
	{
		std::cerr << "Usage: ./PmergeMe [sequence]" << std::endl;
		return (1);
	}
	else
	{
		try
		{
			vec = validateArgs(argc, argv);
			deq.assign(vec.begin(), vec.end());

			std::cout << "Before: ";
			for (size_t i = 0; i < vec.size(); i++)
				std::cout << vec[i] << " ";
			std::cout << std::endl;

			std::vector<int> sortedVec = recursiveMergeSort(vec);
			std::cout << "After: ";
			for (size_t i = 0; i < sortedVec.size(); i++)
				std::cout << sortedVec[i] << ' ';
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}