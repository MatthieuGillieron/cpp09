
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
	std::string sep = ",";
	std::string buffer;
	std::string value = "";

	std::ifstream readFile(file);
	if (!readFile)
	{
		std::cout << "Cannot open this file" << std::endl;
		return;
	}

	while (getline(readFile, buffer))
	{
		size_t pos = buffer.find(sep);
		if (pos != std::string::npos)
		{
			std:: string key = buffer.substr(0, pos);
			std::cout << "trouver le sep" << key << std::endl;

		}
	}


	readFile.close();
}

// check si open, et non null



// void checkInput(const std::string &file)
// {

// }