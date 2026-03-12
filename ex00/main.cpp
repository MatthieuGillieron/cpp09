
#include "BitcoinExchange.hpp"

int main()
{

	std::map<std::string, int> mp;
	std::map<std::string, int>::iterator it;


	mp.insert(std::make_pair<std::string>("key", 2));
	mp.insert(std::make_pair<std::string>("key2", 1));
	mp.insert(std::make_pair<std::string>("key3", 3));

	for (it = mp.begin();  it !=  mp.end(); it++)
		std::cout << it->first << " | " << it->second << std::endl;


}


// key ,value
// une ligne = une paires
