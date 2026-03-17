
#include "BitcoinExchange.hpp"
#include <sstream>

// === CANONICAL FORM === 

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data)
{}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_data = other._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{}


// === UTILS ===


bool parseValue(float value)
{
	if (value < 0)
	{
		std::cout << "Error: not a positive number" << std::endl;
		return false;
	}
	if (value > 1000)
	{
		std::cout << "Error: too large a number" << std::endl;
		return false;
	}
	return true;
}


bool parseLine(const std::string &line, std::string &key, float &value)
{
	size_t pos = line.find("|");
	if (pos == std::string::npos)
		return false;
	
	key = line.substr(0, pos);
	std::string strValue = line.substr(pos + 1);

	std::istringstream convertValue(strValue);
	convertValue >> value;
	
	return true;
}



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
	
	std::ifstream readFile(file);
	if (!readFile)
	{
		std::cout << "Cannot open this file" << std::endl;
		return;
	}

	std::string line;
	getline(readFile, line);
	while (getline(readFile, line))
	{
		std::string key;
		float value;

		if (!parseLine(line, key, value))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
			
			if (!parseValue(value))
				continue;
			
			std::map<std::string, float>::iterator it = _data.lower_bound(key);
			if (it->first ==  key)
			{
				float result = it ->second * value;
				std::cout << key << " => " << value << " = " << result << std::endl;
			}
			if (it->first != key)
			{
				if (it == _data.begin())
					std::cout << "Error: no valid date found" << std::endl;
				else
				{
					it--;
					float result = it->second * value;
					std::cout << key << " => " << value << " = " << result << std::endl;
				}

			}
	}
	readFile.close();
}