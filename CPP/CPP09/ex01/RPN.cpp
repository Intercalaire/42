/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:17:16 by vgodart           #+#    #+#             */
/*   Updated: 2025/03/19 23:17:19 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>

RPN::RPN() {}

RPN::RPN(const RPN &copy) {
	*this = copy;
}

RPN &RPN::operator=(const RPN &copy) {
	if (this != &copy) {
		this->_stack = copy._stack;
	}
	return *this;
}

RPN::~RPN() {}

void RPN::performOperation(char op) {
	if (_stack.size() < 2) {
		throw std::runtime_error("Error: Not enough operands");
	}

	int val2 = _stack.top();
	_stack.pop();
	int val1 = _stack.top();
	_stack.pop();

	switch (op) {
		case '+':
			_stack.push(val1 + val2);
			break;
		case '-':
			_stack.push(val1 - val2);
			break;
		case '*':
			_stack.push(val1 * val2);
			break;
		case '/':
			if (val2 == 0) {
				throw std::runtime_error("Error: Division by zero");
			}
			_stack.push(val1 / val2);
			break;
	}
}

int RPN::evaluate(const std::string& expression) {
	std::stringstream ss(expression);
	std::string token;

	while (ss >> token) {
		
		if (token.length() == 1 && std::isdigit(token[0])) {
			_stack.push(token[0] - '0');
		}

		else if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
			performOperation(token[0]);
		}

		else {
			throw std::runtime_error("Error: Invalid token");
		}
	}

	if (_stack.size() != 1) {
		throw std::runtime_error("Error: Invalid expression");
	}

	return _stack.top();
}