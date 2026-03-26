
#include "PmergeMe.hpp"

//  === CANONICAL FORM ===

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq)
{}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vec = (other._vec);
		_deq = (other._deq);
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{}

void PmergeMe::parseInput(int ac, char **av)
{
	if (ac < 2)
	{
		throw std::runtime_error("try: ./pmergeme <list_of_number>");
		return;
	}


	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; av[i][j]; j++)
		{
			if (!isdigit(av[i][j]))
			{
				throw std::runtime_error("error: only digit is requiert");
				return;
			}
		}

		long val = std::strtol(av[i], NULL, 10);
		if (val < 0 || val > INT_MAX)
		{
			throw std::runtime_error("error: range autorized: 0 - 2147483647");
			return;
		}
		_vec.push_back(val);
		_deq.push_back(val);
		
	}

}


// ===  SORT FOR VECTOR ===

void PmergeMe::fordJohnsonVec(std::vector<int> &vec)
{
	int impair = -1;
	if (vec.size() <= 1)
		return;

	if (vec.size() % 2 != 0)
		impair = vec.back();
	
	std::vector<int> big;
	std::vector<int> little;

	for (int i = 0; i + 1 < (int)vec.size(); i += 2)
	{
		if (vec[i] < vec [i + 1])
		{
			little.push_back(vec[i]);
			big.push_back(vec[i + 1]);

		}
		else
		{
			big.push_back(vec[i]);
			little.push_back(vec[i + 1]);
		}

	}
	std::vector<int> orginalBig = big;
	fordJohnsonVec(big);
	big.insert(big.begin(), little[0]);
	
	int n = 1;
	while (jacobsthal(n) < (int)little.size())
	{
		for (int i = jacobsthal(n); i > jacobsthal(n-1); i--)
		{
			std::vector<int>::iterator it = std::find(big.begin(), big.end(), orginalBig[i]);
			int end = it - big.begin();

			binaryInsertVec(big, little[i], end);
		}
		n++;
	}
	if (impair != -1)
		binaryInsertVec(big, impair, big.size());

	vec = big;
}


int PmergeMe::jacobsthal(int n)
{
	if ( n == 0)
		return 0;
	if (n == 1)
		return 1;
	else
		n = jacobsthal(n-1) + 2 * jacobsthal(n-2);

	return n;
}

void PmergeMe::binaryInsertVec(std::vector<int> &vec, int val, int end)
{
	int left = 0;
	int right = end;

	while (left < right)
	{
		int mid = (left + right) / 2;
		if (val > vec[mid])
			left = mid + 1;
		else
			right = mid;
	}
	vec.insert(vec.begin() + left, val);
}


// === SORT FOR DEQUE ===



void PmergeMe::fordJohnsonDeque(std::deque<int> &deq)
{
	int impair = -1;
	if (deq.size() <= 1)
		return;

	if (deq.size() % 2 != 0)
		impair = deq.back();
	
	std::deque<int> big;
	std::deque<int> little;

	for (int i = 0; i + 1 < (int)deq.size(); i += 2)
	{
		if (deq[i] < deq [i + 1])
		{
			little.push_back(deq[i]);
			big.push_back(deq[i + 1]);

		}
		else
		{
			big.push_back(deq[i]);
			little.push_back(deq[i + 1]);
		}

	}
	std::deque<int> orginalBig = big;
	fordJohnsonDeque(big);
	big.insert(big.begin(), little[0]);
	
	int n = 1;
	while (jacobsthal(n) < (int)little.size())
	{
		for (int i = jacobsthal(n); i > jacobsthal(n-1); i--)
		{
			std::deque<int>::iterator it = std::find(big.begin(), big.end(), orginalBig[i]);
			int end = it - big.begin();

			binaryInsertDeque(big, little[i], end);
		}
		n++;
	}
	if (impair != -1)
		binaryInsertDeque(big, impair, big.size());

	deq = big;
}


void PmergeMe::binaryInsertDeque(std::deque<int> &deq, int val, int end)
{
	int left = 0;
	int right = end;

	while (left < right)
	{
		int mid = (left + right) / 2;
		if (val > deq[mid])
			left = mid + 1;
		else
			right = mid;
	}
	deq.insert(deq.begin() + left, val);
}


void PmergeMe::sortVector()
{
	clock_t start = clock();
	fordJohnsonVec(_vec);
	clock_t end = clock();

	_timeVec = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
}


void PmergeMe::sortDeque()
{
	clock_t start = clock();
	fordJohnsonDeque(_deq);
	clock_t end = clock();

	_timeDeq = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
} 


// === 	DISPLAY ===

void PmergeMe::displayResult(std::string when)
{
	std::cout << when << ": ";
	for (int i = 0; i < (int)_vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;
}


void PmergeMe::displayTime()
{
	
	std::cout << "Time to process a range of " <<  _vec.size() << " elements with std::vector : ";
	std::cout << _timeVec << " us" << std::endl;

	std::cout << "Time to process a range of " <<  _vec.size() << " elements with std::deque : ";
	std::cout << _timeDeq << " us" << std::endl;
}