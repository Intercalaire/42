/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:38:52 by vgodart           #+#    #+#             */
/*   Updated: 2024/12/04 12:35:26 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	std::string name;
	PhoneBook phonebook;

	while (1 && !std::cin.eof())
	{
		std::cout << "ENTREZ UNE COMMANDE" << std::endl;
		std::getline (std::cin,name);
		if (name == "EXIT")
			break;
		else if (name == "ADD"){
			phonebook.ADD();
		}
		else if (name == "SEARCH")
		{
			phonebook.SEARCH();
		}
	}
	return (0);
}
