/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:17:16 by vgodart           #+#    #+#             */
/*   Updated: 2025/03/19 23:17:19 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <cerrno>
#include <climits>

class ScalarConverter{

	public:
		static void convert(const std::string& literal);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);
		~ScalarConverter();

		static void convertFromChar(char c);
		static void convertFromInt(int n);
		static void convertFromFloat(float f);
		static void convertFromDouble(double d);
		
		static void convertSpecialInfinity(const std::string& literal);
		static void convertSpecialNaN();

		static bool safeAtoi(const std::string& str, int& result);

		static bool isIntLiteral(const std::string&);
		static bool isFloatLiteral(const std::string&);
		static bool isDoubleLiteral(const std::string&);
	
};

#endif