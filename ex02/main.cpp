
#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe pm;

	try
	{
		pm.parseInput(ac, av);
		pm.displayResult("before");
		pm.sortVector();
		pm.sortDeque();
		pm.displayResult("after");
		pm.displayTime();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;

}