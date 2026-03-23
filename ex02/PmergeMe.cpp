
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