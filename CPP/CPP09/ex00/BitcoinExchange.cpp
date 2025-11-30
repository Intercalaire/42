/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:17:16 by vgodart           #+#    #+#             */
/*   Updated: 2025/03/19 23:17:19 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <cstdlib>

#define RED   "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"


bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(const std::string& date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	int year, month, day;
	char sep1, sep2;
	std::stringstream ss(date);
	if (!(ss >> year >> sep1 >> month >> sep2 >> day))
		return (false);

	if (ss.rdbuf()->in_avail() != 0)
		return (false);

	if (sep1 != '-' || sep2 != '-')
		return (false);
	if (month < 1 || month > 12)
		return (false);
	int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if (month == 2 && isLeapYear(year))
		daysInMonth[2] = 29;
	if (day < 1 || day > daysInMonth[month])
		return (false);
	return (true);
}

static std::string trim(const std::string& s) {
	size_t start = s.find_first_not_of(" \t\r\n");
	size_t end = s.find_last_not_of(" \t\r\n");
	if (start == std::string::npos || end == std::string::npos)
		return ("");
	return (s.substr(start, end - start + 1));
}

BitcoinExchange::BitcoinExchange(const std::string& dbFile)
{
    std::ifstream file(dbFile.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file.");

    std::string line;
    if (!std::getline(file, line))
        throw std::runtime_error("Error: database file is empty.");

    while (std::getline(file, line))
    {
        if (line.empty()) continue;

        size_t splitPos = line.find(',');
        if (splitPos == std::string::npos)
            throw std::runtime_error("Error: bad format in database => " + line);

        std::string date = trim(line.substr(0, splitPos));
        std::string rateStr = trim(line.substr(splitPos + 1));

        if (!isValidDate(date))
        {
            throw std::runtime_error("Error: invalid date in database => " + date);
        }

        if (_data.find(date) != _data.end())
            throw std::runtime_error("Error: duplicate date in database => " + date);

        char* endPtr;
        double rate = std::strtod(rateStr.c_str(), &endPtr);
        if (*endPtr != '\0')
            throw std::runtime_error("Error: invalid rate format => " + rateStr);

        _data[date] = rate;
    }
}

double BitcoinExchange::getRate(const std::string& date) const {
	std::map<std::string, double>::const_iterator it = _data.lower_bound(date);

	if (it == _data.begin() && it->first != date)
	{
		throw std::runtime_error("Error: date is too old (no data available).");
	}
	
	if (it == _data.end() || it->first != date)
	{
		--it;
	}
	return (it->second);
}

void BitcoinExchange::processFile(const std::string& dbFile, const std::string& inputFile)
{
	BitcoinExchange btc(dbFile); 

	std::ifstream input(inputFile.c_str());
	if (!input.is_open())
	{
		throw std::runtime_error("Error: could not open file.");
	}
	std::string line;
	
	if (!std::getline(input, line))
	{
		throw std::runtime_error("Error: empty input file.");
	}
	std::string header = trim(line);
	if (header != "date | value")
	{
		throw std::runtime_error("Error: bad header => " + header);
	}

	while (std::getline(input, line))
	{
		if (line.empty()) continue;
		try
		{
			std::string date, valueStr;
			size_t sepPos = line.find('|');

			if (sepPos == std::string::npos)
			{
				throw std::runtime_error("Error: bad input => " + line);
			}

			date = trim(line.substr(0, sepPos));
			valueStr = trim(line.substr(sepPos + 1));

			if (!isValidDate(date))
			{
				throw std::runtime_error("Error: bad input => " + date);
			}

			if (valueStr.empty())
			{
				throw std::runtime_error("Error: bad value.");
			}

			char* endPtr;
			double value = std::strtod(valueStr.c_str(), &endPtr);

			if (*endPtr != '\0' && *endPtr != 'f')
			{
				throw std::runtime_error("Error: bad value (not a number).");
			}

			if (value < 0)
			{
				throw std::runtime_error("Error: not a positive number.");
			}
			if (value > 1000)
			{
				throw std::runtime_error("Error: too large a number.");
			}

			double rate = btc.getRate(date);

			std::cout << date << " => " << value
					  << " = " << value * rate
					  << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Error: " << e.what() + 7 << std::endl;
		}
	}
}