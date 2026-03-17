
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





	// std::map<std::string, int> mp;
	// std::map<std::string, int>::iterator it;


	// mp.insert(std::make_pair<std::string>("key", 2));
	// mp.insert(std::make_pair<std::string>("key2", 1));
	// mp.insert(std::make_pair<std::string>("key3", 3));

	// for (it = mp.begin();  it !=  mp.end(); it++)
	// 	std::cout << it->first << " | " << it->second << std::endl;

	
	// std::cout << std::endl;
	// std::cout << "Test ifstream" << std::endl;

	// std::string output_test;
	
	// std::ifstream readFile("test.txt");
	// while (getline(readFile, output_test))
	// 	std::cout << output_test;

	// readFile.close();
}


// key ,value
// une ligne = une paires
