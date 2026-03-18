
#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "exec: ./RPN <calcul>" << std::endl;
		return 1;
	}

	RPN rpn;
	rpn.process(av[1]);
}