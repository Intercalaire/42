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

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	try {
		std::vector<int>::const_iterator it = easyfind(vec, 20);
		std::cout << "Trouvé dans vector: " << *it << std::endl;
	}
	catch (std::exception const& e) {
		std::cerr << "Erreur vector: " << e.what() << std::endl;
	}

	try {
		std::vector<int>::const_iterator it = easyfind(vec, 99);
		std::cout << "Trouvé dans vector: " << *it << std::endl;
	}
	catch (std::exception const& e) {
		std::cerr << "Erreur vector: " << e.what() << std::endl;
	}

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(15);
	lst.push_back(25);

	try {
		std::list<int>::const_iterator it = easyfind(lst, 25);
		std::cout << "Trouvé dans list: " << *it << std::endl;
	}
	catch (std::exception const& e) {
		std::cerr << "Erreur list: " << e.what() << std::endl;
	}

	try {
		std::list<int>::const_iterator it = easyfind(lst, -1);
		std::cout << "Trouvé dans list: " << *it << std::endl;
	}
	catch (std::exception const& e) {
		std::cerr << "Erreur list: " << e.what() << std::endl;
	}

	return 0;
}
