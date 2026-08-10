#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>

# include <ctime>
# include <cstdlib>
# include <climits>

# include <deque>
# include <vector>
# include <utility>
# include <algorithm>
# include <stdexcept>

typedef std::pair<int, int> Pair;

std::vector<int>	validateArgs(int argc, char **argv);

std::vector<Pair>	createSortedPairs(const std::vector<int> &vec);
std::vector<int>	extractLargerElements(const std::vector<Pair> &pairs);
int					checkStray(const std::vector<int> &vec);
int					binarySearchInsert(const std::vector<int> &vec, int target, int low, int high);
std::vector<int>	recursiveMergeSort(std::vector<int> &vec);

std::deque<Pair>	createSortedPairsDeque(const std::deque<int> &deq);
std::deque<int>		extractLargerElementsDeque(const std::deque<Pair> &pairs);
int					checkStrayDeque(const std::deque<int> &deq);
int					binarySearchInsertDeque(const std::deque<int> &deq, int target, int low, int high);
std::deque<int>		recursiveMergeSortDeque(std::deque<int> &deq);

std::vector<int>	generateJacobsthalNumbers(int n);
std::deque<int>		timedDequeSort(const std::deque<int> &input, double &elapsedMs);
std::vector<int>	timedVectorSort(const std::vector<int> &input, double &elapsedMs);
class CustomException : public std::runtime_error
{
	public:
		explicit CustomException(std::string err);
};

#endif
