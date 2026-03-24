
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
	fordJohnsonVec(big);
	big.insert(big.begin(), little[0]);
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
	
}