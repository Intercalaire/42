/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:17:16 by vgodart           #+#    #+#             */
/*   Updated: 2025/03/19 23:17:19 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

#define RED   "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED << "Error: could not open file." << RESET << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange::processFile("data.csv", argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		return (1);
	}
	return (0);
}
