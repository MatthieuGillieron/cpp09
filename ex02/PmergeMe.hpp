
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
#include <iostream>
#include <iomanip>


class PmergeMe
{

	private:

		std::vector<int> _vec;
		std::deque<int> _deq;
		double _timeVec;
    	double _timeDeq;
		
		void fordJohnsonVec(std::vector<int> &vec);
    	void fordJohnsonDeque(std::deque<int> &deq);
		void binaryInsertVec(std::vector<int> &vec, int val, int end);
		void binaryInsertDeque(std::deque<int> &deq, int val, int end);

		int  jacobsthal(int n);

	public:

		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe & operator=(const PmergeMe &other);
		~PmergeMe();

		void parseInput(int ac, char **av);
		void sortVector();
		void sortDeque();
		void displayResult(std::string when);
		void displayTime();


};


#endif