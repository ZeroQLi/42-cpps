#include "PmergeMe.hpp"


// Checking and Helper Functions
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

std::vector<int> generateJacobsthalNumbers(int n)
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

static std::vector<int> generateInsertionOrder(int pairCount)
{
	std::vector<int> order;
	std::vector<int> jacobNumbers;
	int previous;

	if (pairCount <= 1)
		return order;
	jacobNumbers = generateJacobsthalNumbers(pairCount);
	previous = 1;
	for (size_t i = 0; i < jacobNumbers.size() && previous < pairCount; ++i)
	{
		int upper = jacobNumbers[i];

		if (upper <= previous)
			continue ;
		if (upper > pairCount)
			upper = pairCount;
		for (int pairIndex = upper; pairIndex > previous; --pairIndex)
			order.push_back(pairIndex - 1);
		previous = upper;
	}
	return order;
}

static std::vector<Pair> orderPairsByLarger(
	const std::vector<Pair> &pairs, const std::vector<int> &largerElements)
{
	std::vector<Pair> orderedPairs;

	orderedPairs.reserve(pairs.size());
	for (size_t i = 0; i < largerElements.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (pairs[j].first == largerElements[i])
			{
				orderedPairs.push_back(pairs[j]);
				break ;
			}
		}
	}
	return orderedPairs;
}

// Timing Functions
std::vector<int> timedVectorSort(std::vector<int> &vec, double &elapsedMs)
{
	std::clock_t start = std::clock();
	std::vector<int> result = recursiveMergeSort(vec);
	std::clock_t end = std::clock();

	elapsedMs = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
	return result;
}

std::deque<int> timedDequeSort(std::deque<int> &deq, double &elapsedMs)
{
	std::clock_t start = std::clock();
	std::deque<int> result = recursiveMergeSortDeque(deq);
	std::clock_t end = std::clock();

	elapsedMs = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
	return result;
}

// Vector Functions

std::vector<Pair>	createSortedPairs(const std::vector<int> &vec)
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

std::vector<int>	extractLargerElements(const std::vector<Pair> &pairs)
{
	std::vector<int> largerInts;
	largerInts.reserve(pairs.size());

	for (size_t i = 0; i < pairs.size(); ++i)
		largerInts.push_back(pairs[i].first);
	return largerInts;
}

int	checkStray(const std::vector<int> &vec)
{
	if (vec.size() % 2 != 0)
		return vec[vec.size() - 1];
	return -1;
}

int	binarySearchInsert(const std::vector<int> &vec, int target, int low, int high)
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

static void insertPendingVector(std::vector<int> &mainChain,
	const std::vector<Pair> &orderedPairs)
{
	std::vector<int> insertionOrder;

	if (orderedPairs.empty())
		return ;
	mainChain.insert(mainChain.begin(), orderedPairs[0].second);
	insertionOrder = generateInsertionOrder(orderedPairs.size());
	for (size_t i = 0; i < insertionOrder.size(); ++i)
	{
		int pairIndex = insertionOrder[i];
		int partnerPosition = 0;
		int insertPosition;

		while (partnerPosition < static_cast<int>(mainChain.size())
			&& mainChain[partnerPosition] != orderedPairs[pairIndex].first)
			++partnerPosition;
		insertPosition = binarySearchInsert(mainChain,
			orderedPairs[pairIndex].second, 0, partnerPosition);
		mainChain.insert(mainChain.begin() + insertPosition,
			orderedPairs[pairIndex].second);
	}
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
	insertPendingVector(main_chain, orderPairsByLarger(pairs, main_chain));
	if (stray != -1)
	{
		int insertPos = binarySearchInsert(main_chain, stray, 0, main_chain.size());
		main_chain.insert(main_chain.begin() + insertPos, stray);
	}
	return main_chain;
}

// Deque Functions

std::deque<Pair>	createSortedPairsDeque(const std::deque<int> &deq)
{
	std::deque<Pair> pairs;

	for (size_t i = 0; i + 1 < deq.size(); i += 2)
	{
		int first = deq[i];
		int second = deq[i + 1];

		if (first > second)
			pairs.push_back(std::make_pair(first, second));
		else
			pairs.push_back(std::make_pair(second, first));
	}
	return pairs;
}

static std::deque<Pair> orderPairsByLargerDeque(
	const std::deque<Pair> &pairs, const std::deque<int> &largerElements)
{
	std::deque<Pair> orderedPairs;

	for (size_t i = 0; i < largerElements.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (pairs[j].first == largerElements[i])
			{
				orderedPairs.push_back(pairs[j]);
				break ;
			}
		}
	}
	return orderedPairs;
}

static void insertPendingDeque(std::deque<int> &mainChain,
	const std::deque<Pair> &orderedPairs)
{
	std::vector<int> insertionOrder;

	if (orderedPairs.empty())
		return ;
	mainChain.push_front(orderedPairs[0].second);
	insertionOrder = generateInsertionOrder(orderedPairs.size());
	for (size_t i = 0; i < insertionOrder.size(); ++i)
	{
		int pairIndex = insertionOrder[i];
		int partnerPosition = 0;
		int insertPosition;

		while (partnerPosition < static_cast<int>(mainChain.size())
			&& mainChain[partnerPosition] != orderedPairs[pairIndex].first)
			++partnerPosition;
		insertPosition = binarySearchInsertDeque(mainChain,
			orderedPairs[pairIndex].second, 0, partnerPosition);
		mainChain.insert(mainChain.begin() + insertPosition,
			orderedPairs[pairIndex].second);
	}
}

std::deque<int>	extractLargerElementsDeque(const std::deque<Pair> &pairs)
{
	std::deque<int> largerInts;

	for (size_t i = 0; i < pairs.size(); ++i)
		largerInts.push_back(pairs[i].first);
	return largerInts;
}

int	checkStrayDeque(const std::deque<int> &deq)
{
	if (deq.size() % 2 != 0)
		return deq[deq.size() - 1];
	return -1;
}

int	binarySearchInsertDeque(const std::deque<int> &deq, int target, int low, int high)
{
	int mid;

	while (low < high)
	{
		mid = low + (high - low) / 2;
		if (deq[mid] < target)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

std::deque<int>	recursiveMergeSortDeque(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return deq;
	if (deq.size() == 2)
	{
		if (deq[0] > deq[1])
			std::swap(deq[0], deq[1]);
		return deq;
	}
	std::deque<Pair> pairs = createSortedPairsDeque(deq);
	int stray = checkStrayDeque(deq);

	std::deque<int> larger_elements = extractLargerElementsDeque(pairs);
	std::deque<int> main_chain = recursiveMergeSortDeque(larger_elements);
	insertPendingDeque(main_chain, orderPairsByLargerDeque(pairs, main_chain));
	if (stray != -1)
	{
		int insertPos = binarySearchInsertDeque(main_chain, stray, 0, main_chain.size());
		main_chain.insert(main_chain.begin() + insertPos, stray);
	}
	return main_chain;
}
