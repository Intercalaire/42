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

#include "iter.hpp"

int main()
{
	std::cout << "=== Test with integers ===" << std::endl;
	int numbers[] = {1, 2, 3, 4, 5};
	
	std::cout << "Array original:" << std::endl;
	iter(numbers, 5, printElement<int>);
	
	std::cout << "\nAfter doubleValue:" << std::endl;
	iter(numbers, 5, doubleValue<int>);
	iter(numbers, 5, printElement<int>);
	
	std::cout << "\nAfter incrementValue:" << std::endl;
	iter(numbers, 5, incrementValue<int>);
	iter(numbers, 5, printElement<int>);
	
	std::cout << "\n=== Test with doubles ===" << std::endl;
	double doubles[] = {1.1, 2.2, 3.3};
	
	std::cout << "Array original:" << std::endl;
	iter(doubles, 3, printElement<double>);
	
	std::cout << "\nAfter doubleValue:" << std::endl;
	iter(doubles, 3, doubleValue<double>);
	iter(doubles, 3, printElement<double>);
	
	std::cout << "\n=== Test with characters ===" << std::endl;
	char chars[] = {'a', 'b', 'c', 'd'};
	
	std::cout << "Array original:" << std::endl;
	iter(chars, 4, printElement<char>);
	
	std::cout << "\nAfter toUpperCase:" << std::endl;
	iter(chars, 4, toUpperCase<char>);
	iter(chars, 4, printElement<char>);
	
	std::cout << "\n=== Test with strings ===" << std::endl;
	std::string strings[] = {"goodnight", "world", "test"};
	
	std::cout << "Array original:" << std::endl;
	iter(strings, 3, printElement<std::string>);
	
	std::cout << "\n=== Test printArray ===" << std::endl;
	printArray(numbers, 5);
	printArray(doubles, 3);
	
	return 0;
}