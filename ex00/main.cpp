
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{

	if (ac != 2)
	{
		std::cout << "execute: ./btc <file.txt>" << std::endl;
		return 1;
	}

	BitcoinExchange btc;
	btc.loadDB("data.csv");
	btc.checkInput(av[1]);
}