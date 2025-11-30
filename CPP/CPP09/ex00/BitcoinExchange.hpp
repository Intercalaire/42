/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:17:16 by vgodart           #+#    #+#             */
/*   Updated: 2025/03/19 23:17:19 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
