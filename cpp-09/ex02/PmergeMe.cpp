#include "PmergeMe.hpp"

std::vector<int> validateArgs(int argc, char **argv)
{
	std::vector<int>	sequence;
	for (int i = 1; i < argc; i++)
	{
		std::istringstream iss(argv[i]);
		long val;
		iss >> val;
		if (iss.fail() || !iss.eof() || val > INT_MAX || val < 0)
			throw CustomException("error: invalid integer in sequence");
		int num = static_cast<int>(val);

		if (std::find(sequence.begin(), sequence.end(), num) != sequence.end())
			throw CustomException("error: duplicate integer in sequence");
		sequence.push_back(num);
	}
	return sequence;
}

std::vector<Pair> createSortedPairs(const std::vector<int> &vec)
{
	std::vector<Pair> pairs;

	// Group elements into pairs
	for (size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		int first = vec[i];
		int second = vec[i + 1];

		if (first > second)
			pairs.push_back(std::make_pair(first, second));
		else
			pairs.push_back(std::make_pair(second, first));
	}
	return pairs;
}

std::vector<int> extractLargerElements(const std::vector<Pair> &pairs)
{
	std::vector<int> largerInts;
	largerInts.reserve(pairs.size());

	for (size_t i = 0; i < pairs.size(); ++i)
		largerInts.push_back(pairs[i].first);
	return largerInts;
}

std::vector<int> extractSmallerElements(const std::vector<Pair> &pairs)
{
	std::vector<int> SmallerInts;
	SmallerInts.reserve(pairs.size());

	for (size_t i = 0; i < pairs.size(); ++i)
		SmallerInts.push_back(pairs[i].second);
	return SmallerInts;
}

int	checkStray(const std::vector<int> &vec)
{
	if (vec.size() % 2 != 0)
		return vec[vec.size() - 1];
	return -1;
}

std::vector<int>	generateJacobsthalNumbers(int n)
{
	std::vector<int> jacob;

	if (n <= 0)
		return jacob;

	jacob.push_back(0); // J(0) - wikipedia starts it at 0 so better do so myself
	jacob.push_back(1);

	while (jacob.back() < n + 1)
	{
		int next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
		jacob.push_back(next);
	}
	jacob.erase(jacob.begin());
	return jacob;
}

int binarySearchInsert(const std::vector<int> &vec, int target, int low, int high)
{
	int	mid;

	while (low < high)
	{
		mid = low + (high - low) / 2;
		if (vec[mid] < target)
			low = mid + 1; // Target belongs in right half
		else
			high = mid; // Target belongs in left half (including mid)
	}
	return low; // This is the insertion position
}

std::vector<int> recursiveMergeSort(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return vec;
	if (vec.size() == 2)
	{
		if (vec[0] > vec[1])
			std::swap(vec[0], vec[1]);
		return vec;
	}
	std::vector<Pair> pairs = createSortedPairs(vec);
	int stray = checkStray(vec);

	std::vector<int> larger_elements = extractLargerElements(pairs);
	std::vector<int> main_chain = recursiveMergeSort(larger_elements);
	std::vector<int> pend_chain = extractSmallerElements(pairs);
	if (!pend_chain.empty())
	{
		main_chain.insert(main_chain.begin(), pend_chain[0]);
		pend_chain.erase(pend_chain.begin());
	}
	// jacobshatl thingies
	std::vector<int> jacobNumbers = generateJacobsthalNumbers(pend_chain.size());

	for (size_t i = 0; i < jacobNumbers.size(); ++i)
	{
		int pendIndex = jacobNumbers[i] - 1;

		// Check if this index is valid in pend_chain
		if (pendIndex >= 0 && pendIndex < static_cast<int>(pend_chain.size()))
		{
			int elementToInsert = pend_chain[pendIndex];
			// Find correct position using binary search
			int insertPos = binarySearchInsert(main_chain, elementToInsert, 0, main_chain.size());
			// Insert at the found position
			main_chain.insert(main_chain.begin() + insertPos, elementToInsert);
			pend_chain.erase(pend_chain.begin() + pendIndex);
		}
	}
	for (size_t i = 0; i < pend_chain.size(); ++i)
	{
		int insertPos = binarySearchInsert(main_chain, pend_chain[i], 0, main_chain.size());
		main_chain.insert(main_chain.begin() + insertPos, pend_chain[i]);
	}
	if (stray != -1)
	{
		int insertPos = binarySearchInsert(main_chain, stray, 0, main_chain.size());
		main_chain.insert(main_chain.begin() + insertPos, stray);
	}
	return main_chain;
}