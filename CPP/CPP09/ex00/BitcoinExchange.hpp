
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>

class BitcoinExchange {
private:
	std::map<std::string, double> _data;
public:
	BitcoinExchange(const std::string& dbFile);
	double getRate(const std::string& date) const;
	static void processFile(const std::string& dbFile, const std::string& inputFile);
};

#endif
