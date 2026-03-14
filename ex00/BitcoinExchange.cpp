
#include "BitcoinExchange.hpp"
#include <sstream>

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
	float fValue;

	std::ifstream readFile(file);
	if (!readFile)
	{
		std::cout << "Cannot open this file" << std::endl;
		return;
	}
	getline(readFile, buffer);
	while (getline(readFile, buffer))
	{
		size_t pos = buffer.find(sep);
		if (pos != std::string::npos)
		{
			std:: string key = buffer.substr(0, pos);
			std:: string value = buffer.substr(pos + 1);

			std::istringstream convertValue(value);
			convertValue >> fValue;

			_data.insert(std::make_pair(key, fValue));
			
		}
	}
	readFile.close();
}

// void checkInput(const std::string &file)
// {

// }



	// std::map<std::string, float>::iterator it;
	// std::map<std::string, float>::iterator it1;
	// it = _data.begin();
	// it1 = _data.end();
	
	// while (it  != it1)
	// {
	// 	std::cout << "key: " << it->first << " value: " << it->second << std::endl;
	// 	it++;
	// }