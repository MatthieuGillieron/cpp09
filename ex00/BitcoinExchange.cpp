
#include "BitcoinExchange.hpp"

// === CANONICAL FORM === 

BitcoinExchange::BitcoinExchange()
{}

// BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
// {

// }

// BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
// {

// }



BitcoinExchange::~BitcoinExchange()
{}

// === METHODE === 

void BitcoinExchange::loadDB(const std::string &file)
{
	if (!std::ifstream("data.csv"))
	{
		std::cout << "Cannot open this file" << std::endl;
		return;
	}
	std::string sep = ",";
	std::string buffer;

	std::ifstream readFile(file);
	while (getline(readFile, buffer))
	{
		size_t pos = buffer.find(sep);
		if (pos != std::string::npos)
		{
			std::cout << "trouver le sep" << sep << std::endl;
		}
	}


	readFile.close();
}

// check si open, et non null



// void checkInput(const std::string &file)
// {

// }