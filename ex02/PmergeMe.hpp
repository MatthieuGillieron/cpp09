
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>
#include <deque>
#include <ctime>
#include <exception>

class PmergeMe
{

	private:

		std::vector<int> _vec;
		std::deque<int> _deq;

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