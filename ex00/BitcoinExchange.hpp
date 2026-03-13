
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>

class BitcoinExchange
{
	private:

		std::map<std::string, float> _data;



	public:

		BitcoinExchange();
		// BitcoinExchange(const BitcoinExchange &other);
		// BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void loadDB(const std::string &file);
		//void checkInput(const std::string &file);


};

#endif