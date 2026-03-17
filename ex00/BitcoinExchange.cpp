
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

void BitcoinExchange::checkInput(const std::string &file)
{
	std::string sep = "|";
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
			std::string key = buffer.substr(0, pos);
			std::string value = buffer.substr(pos + 1);
		
			std::istringstream convertValue(value);
			convertValue >> fValue;
			
			if (fValue < 0 || fValue > 1000)
			{
				if (fValue < 0)
				{
					std::cout << "Error: not a positive number" << std::endl;
					continue;
				}

				else
				{
					std::cout << "Error: too large a number" << std::endl;
					continue;
				}
			}
			
			std::map<std::string, float>::iterator it = _data.lower_bound(key);
			if (it->first ==  key)
			{
				float result = it ->second * fValue;
				std::cout << key << " => " << fValue << " = " << result << std::endl;
			}
			else
			{
				it--;
				float result = it->second * fValue;
				std::cout << key << " => " << fValue << " = " << result << std::endl;

			}

		}
		else
			std::cout << "Error: bad input => " << buffer << std::endl;
	}
	readFile.close();
}



//void parseFile()




// $> ./btc
// Error: could not open file.
// $> ./btc input.txt
// 2011-01-03 => 3 = 0.9
// 2011-01-03 => 2 = 0.6
// 2011-01-03 => 1 = 0.3
// 2011-01-03 => 1.2 = 0.36
// 2011-01-09 => 1 = 0.32
// Error: not a positive number.
// Error: bad input => 2001-42-42
// 2012-01-11 => 1 = 7.1
// Error: too large a number.
// $>

	// std::map<std::string, float>::iterator it;
	// std::map<std::string, float>::iterator it1;
	// it = _data.begin();
	// it1 = _data.end();
	
	// while (it  != it1)
	// {
	// 	std::cout << "key: " << it->first << " value: " << it->second << std::endl;
	// 	it++;
	// }