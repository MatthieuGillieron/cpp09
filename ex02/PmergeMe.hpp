
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>
#include <deque>

class PmergeMe
{

	private:

		std::vector<int> _vec;
		std::deque<int> _deq;

	public:

		void parseInput(int ac, char **av);
		void sortVector();
		void sortDeque();
		void displayResult();
		void displayTime();


};




#endif