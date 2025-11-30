/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:17:16 by vgodart           #+#    #+#             */
/*   Updated: 2025/03/19 23:17:19 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	(void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
	(void)copy;
	return *this;
}
ScalarConverter::~ScalarConverter() {}


void ScalarConverter::convert(const std::string& literal) {
	if (literal == "+inf" || literal == "-inf") {
		convertSpecialInfinity(literal);
		return;
	}
	if (literal == "+inff" || literal == "-inff") {
		convertSpecialInfinity(literal);
		return;
	}
	if (literal == "nan" || literal == "nanf") {
		convertSpecialNaN();
		return;
	}
	if (literal.length() == 1 && !std::isdigit(literal[0])) {
		convertFromChar(literal[0]);
	}
	else {
		int value;
		if (isIntLiteral(literal) && safeAtoi(literal, value)) {
			convertFromInt(value);
		}
		else if (isFloatLiteral(literal)) {
			float value = std::strtof(literal.c_str(), NULL);
			convertFromFloat(value);
		}
		else if (isDoubleLiteral(literal)) {
			double value = std::strtod(literal.c_str(), NULL);
			convertFromDouble(value);
		}
		else {
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: impossible\n";
			std::cout << "double: impossible\n";
		}
	}
}

bool ScalarConverter::safeAtoi(const std::string& str, int& result) {
	errno = 0;

	char* endPtr;
	long val = std::strtol(str.c_str(), &endPtr, 10);
	if (*endPtr != '\0') {
		return false;
	}
	if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN)) ||
		val > INT_MAX || val < INT_MIN) {
		return false;
	}

	result = static_cast<int>(val);
	return true;
}


bool ScalarConverter::isIntLiteral(const std::string& str) {
	if (str.empty()) return false;
	size_t i = 0;

	if (str[i] == '-' || str[i] == '+') i++;
	while (i < str.length()) {
		if (!std::isdigit(str[i])) return false;
		i++;
	}
	return (true);
}

bool ScalarConverter::isFloatLiteral(const std::string& str) {
	if (str.empty()) return false;
	if (str == "nanf" || str == "+inff" || str == "-inff") return true;
	
	if (str[str.length() - 1] != 'f') return false;
	
	std::string withoutF = str.substr(0, str.length() - 1);
	char* endPtr;
	std::strtof(withoutF.c_str(), &endPtr);
	
	return (*endPtr == '\0' && withoutF.find('.') != std::string::npos);
}

bool ScalarConverter::isDoubleLiteral(const std::string& str) {
	if (str.empty()) return false;
	if (str == "nan" || str == "+inf" || str == "-inf") return true;
	
	char* endPtr;
	std::strtod(str.c_str(), &endPtr);
	
	return (*endPtr == '\0' && str.find('.') != std::string::npos);
}

void ScalarConverter::convertSpecialInfinity(const std::string& literal) {
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	
	if (literal == "+inf" || literal == "+inff") {
		std::cout << "float: +inff\n";
		std::cout << "double: +inf\n";
	} else if (literal == "-inf" || literal == "-inff") {
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
	}
}

void ScalarConverter::convertSpecialNaN() {
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: nanf\n";
	std::cout << "double: nan\n";
}

void ScalarConverter::convertFromChar(char value) {
	int i = static_cast<int>(value);
	float f = static_cast<float>(value);
	double d = static_cast<double>(value);

	std::cout << "char: ";
	if (std::isprint(value)) {
		std::cout << "'" << value << "'\n";
	} else {
		std::cout << "Non displayable\n";
	}
	
	std::cout << "int: " << i << "\n";
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
}

void ScalarConverter::convertFromInt(int value) {
	char c = static_cast<char>(value);
	float f = static_cast<float>(value);
	double d = static_cast<double>(value);

	std::cout << "char: ";
	if (std::isprint(c)) {
		std::cout << "'" << c << "'\n";
	} else {
		std::cout << "Non displayable\n";
	}
	
	std::cout << "int: " << value << "\n";
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
}

void ScalarConverter::convertFromFloat(float value) {
	char c = static_cast<char>(value);
	int i = static_cast<int>(value);
	double d = static_cast<double>(value);

	std::cout << "char: ";
	if (std::isprint(c)) {
		std::cout << "'" << c << "'\n";
	} else {
		std::cout << "Non displayable\n";
	}
	std::cout << "int: " << i << "\n";
	if (value == static_cast<float>(static_cast<int>(value))) {
		std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f\n";
	} else {
		std::cout << "float: " << value << "f\n";
	}
	if (d == static_cast<double>(static_cast<int>(d))) {
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
	} else {
		std::cout << "double: " << d << "\n";
	}
}

void ScalarConverter::convertFromDouble(double value) {
	char c = static_cast<char>(value);
	int i = static_cast<int>(value);
	float f = static_cast<float>(value);

	std::cout << "char: ";
	if (std::isprint(c)) {
		std::cout << "'" << c << "'\n";
	} else {
		std::cout << "Non displayable\n";
	}
	std::cout << "int: " << i << "\n";
	if (f == static_cast<float>(static_cast<int>(f))) {
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
	} else {
		std::cout << "float: " << f << "f\n";
	}
	if (value == static_cast<double>(static_cast<int>(value))) {
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << "\n";
	} else {
		std::cout << "double: " << value << "\n";
	}
}

