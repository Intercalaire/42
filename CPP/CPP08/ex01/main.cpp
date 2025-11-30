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

#include "Span.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

void testSimple() {
	std::cout << "[Simple Test]" << std::endl;
	Span s(5);
	s.addNumber(42);
	s.addNumber(0);
	s.addNumber(21);
	s.addNumber(0);
	s.addNumber(100);
	std::cout << "shortest: " << s.shortestSpan() << ", longest: " << s.longestSpan() << std::endl;
}

void testExceptions() {
	std::cout << "[Exceptions Test]" << std::endl;
	Span s(2);
	try {
		s.addNumber(1);
		s.addNumber(2);
		s.addNumber(3);
		std::cout << "Erreur: pas d'exception sur addNumber" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception attendue (plein): " << e.what() << std::endl;
	}
	Span s2(1);
	s2.addNumber(99);
	try {
		s2.shortestSpan();
		std::cout << "Erreur: pas d'exception sur shortestSpan" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception attendue (pas assez d'éléments): " << e.what() << std::endl;
	}
}

void testRange() {
	std::cout << "[Range Test]" << std::endl;
	Span s(8);
	std::vector<int> vals;
	for (int i = 0; i < 8; ++i) vals.push_back(i * i - 3 * i);
	s.addRange(vals.begin(), vals.end());
	std::cout << "shortest: " << s.shortestSpan() << ", longest: " << s.longestSpan() << std::endl;
}

void testBig() {
	std::cout << "[Big Volume Test]" << std::endl;
	Span s(5000);
	std::vector<int> vals;
	for (int i = 0; i < 5000; ++i) vals.push_back(rand() - rand());
	s.addRange(vals.begin(), vals.end());
	std::cout << "shortest: " << s.shortestSpan() << ", longest: " << s.longestSpan() << std::endl;
}

void testCopy() {
	std::cout << "[Copy/Assignment Test]" << std::endl;
	Span s1(4);
	s1.addNumber(1);
	s1.addNumber(2);
	s1.addNumber(3);
	s1.addNumber(4);
	Span s2 = s1;
	Span s3;
	s3 = s1;
	std::cout << "s2: shortest: " << s2.shortestSpan() << ", longest: " << s2.longestSpan() << std::endl;
	std::cout << "s3: shortest: " << s3.shortestSpan() << ", longest: " << s3.longestSpan() << std::endl;
}

int main() {
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::cout << "====================\n";
	testSimple();
	std::cout << "\n====================\n";
	testExceptions();
	std::cout << "\n====================\n";
	testRange();
	std::cout << "\n====================\n";
	testBig();
	std::cout << "\n====================\n";
	testCopy();
	std::cout << "\n====================\n";
	std::cout << "Fin des tests.\n";
	return 0;
}
