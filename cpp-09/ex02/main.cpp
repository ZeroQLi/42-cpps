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
			double VecTimeMs;
			// double DeqTimeMs;

			vec = validateArgs(argc, argv);
			deq.assign(vec.begin(), vec.end());

			std::cout << "Before: ";
			for (size_t i = 0; i < vec.size() - 1; i++)
				std::cout << vec[i] << " ";
			std::cout << vec[vec.size() - 1] << "\n";

			std::vector<int> sortedVec = timedVectorSort(vec, VecTimeMs);
			std::cout << "After:  ";
			for (size_t i = 0; i < sortedVec.size() - 1; i++)
				std::cout << sortedVec[i] << ' ';
			std::cout << sortedVec[vec.size() - 1] << "\n";
			std::cout << "Time to process a range of " << vec.size() << "elements with std::vector: " << VecTimeMs << " ms\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}