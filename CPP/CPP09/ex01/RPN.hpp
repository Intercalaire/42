
#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <stdexcept>
#include <cctype>

class RPN {
	private:
		std::stack<int> _stack;

		void performOperation(char op);

	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		int evaluate(const std::string& expression);
};

#endif
