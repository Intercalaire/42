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

#include <iostream>
#include "Array.hpp"

int main()
{
	try
	{
		Array<int> arr(50);
		std::cout << "Taille : " << arr.size() << "\n";
		for (unsigned int i = 0; i < arr.size(); ++i)
			arr[i] = i * 3;
		for (unsigned int i = 0; i < arr.size(); ++i)
			std::cout << arr[i] << " ";
		std::cout << "\n";
		std::cout << arr[10] << "\n";
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}
	const Array<std::string> constArr(3);
	std::cout << "Taille const : " << constArr.size() << "\n";
	std::cout << constArr[0] << "\n";

	return 0;
}
