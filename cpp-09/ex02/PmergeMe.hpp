#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <iomanip>

# include <ctime>
# include <cstdlib>
# include <climits>

# include <deque>
# include <vector>
# include <algorithm>

typedef std::pair<int, int> Pair;

std::vector<int>	validateArgs(int argc, char **argv);

std::vector<Pair>	createSortedPairs(const std::vector<int> &vec);
std::vector<int>	extractLargerElements(const std::vector<Pair> &pairs);
std::vector<int>	extractSmallerElements(const std::vector<Pair> &pairs);
int					checkStray(const std::vector<int> &vec);

std::vector<int>	recursiveMergeSort(std::vector<int> &vec);
std::vector<int>	generateJacobsthalNumbers(int n);


class CustomException : public std::runtime_error
{
	public:
		explicit CustomException(std::string err): runtime_error(err) {}
};

#endif

