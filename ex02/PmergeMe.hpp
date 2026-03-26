
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>
#include <deque>
#include <ctime>
#include <exception>
#include <climits>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>


class PmergeMe
{

	private:

		std::vector<int> _vec;
		std::deque<int> _deq;
		
		void fordJohnsonVec(std::vector<int> &vec);
    	void fordJohnsonDeq(std::deque<int> &deq);
		void binaryInsertVec(std::vector<int> &vec, int val, int end);
		int  jacobsthal(int n);

	public:

		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe & operator=(const PmergeMe &other);
		~PmergeMe();

		void parseInput(int ac, char **av);
		void sortVector();
		void sortDeque();
		void displayResult();
		void displayTime();


};


#endif