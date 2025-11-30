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

#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data data = {42, "Its 42 Data"};

	std::cout << "Original Data address: " << &data << std::endl;
	std::cout << "Original Data id: " << data.id << std::endl;
	std::cout << "Original Data message: " << data.message << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "\nSerialized (uintptr_t): " << raw << std::endl;

	Data* deserialized = Serializer::deserialize(raw);
	std::cout << "\nDeserialized Data address: " << deserialized << std::endl;
	std::cout << "Deserialized Data id: " << deserialized->id << std::endl;
	std::cout << "Deserialized Data message: " << deserialized->message << std::endl;

	if (deserialized == &data)
		std::cout << "\nSuccess: The deserialized pointer matches the original!" << std::endl;
	else
		std::cout << "\nError: The deserialized pointer does not match the original!" << std::endl;

	return (0);
}