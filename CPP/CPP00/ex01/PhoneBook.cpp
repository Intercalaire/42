/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 05:59:22 by vgodart           #+#    #+#             */
/*   Updated: 2024/08/23 05:59:24 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static int ft_atoi(std::string str);
static void replaceTabWithSpace(std::string &str);

PhoneBook::PhoneBook() : _nbr_added(0)
{
}

PhoneBook::~PhoneBook()
{
}

static void replaceTabWithSpace(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '\t')
		{
			str[i] = ' ';
		}
	}
}

void PhoneBook::ADD()
{
	std::string answer;

	if (_nbr_added == 8)
		_nbr_added = 0;
	std::cout << "ENTREZ LE PRENOM" << std::endl;
	std::getline (std::cin, answer);
	while (answer == "" && !std::cin.eof())
		std::getline (std::cin, answer);
	replaceTabWithSpace(answer);
	_contact[_nbr_added].SetName(answer);
	std::cout << "ENTREZ LE NOM" << std::endl;
	std::getline (std::cin, answer);
	while (answer == "" && !std::cin.eof())
		std::getline (std::cin, answer);
	replaceTabWithSpace(answer);
	_contact[_nbr_added].SetLastName(answer);
	std::cout << "ENTREZ LE SURNOM" << std::endl;
	std::getline (std::cin, answer);
	while (answer == "" && !std::cin.eof())
		std::getline (std::cin, answer);
	replaceTabWithSpace(answer);
	_contact[_nbr_added].SetNickname(answer);
	std::cout << "ENTREZ LE NUMERO DE TELEPHONE" << std::endl;
	std::getline (std::cin, answer);
	while (answer == "" && !std::cin.eof())
		std::getline (std::cin, answer);
	replaceTabWithSpace(answer);
	_contact[_nbr_added].SetPhoneNumber(answer);
	std::cout << "ENTREZ SON PLUS LOURD SECRET" << std::endl;
	std::getline (std::cin, answer);
	while (answer == "" && !std::cin.eof())
		std::getline (std::cin, answer);
	replaceTabWithSpace(answer);
	_contact[_nbr_added].SetDarkestSecret(answer);
	_nbr_added++;
}


int PhoneBook::SEARCH(void)
{
	int list;
	int index_int;
	std::string index_str;

	list = 1;
	index_int = 0;
	std::cout << "\n|     Index|      Name|Last  Name|  Nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    while(list < 9 && _contact[list - 1].GetName() != "")
    {
        std::string name = _contact[list - 1].GetName();
        std::string lastname = _contact[list - 1].GetLastName();
        std::string nickname = _contact[list - 1].GetNickname();
        if (name.length() > 10)
            name = name.substr(0, 9) + ".";
        if (lastname.length() > 10)
            lastname = lastname.substr(0, 9) + ".";
        if (nickname.length() > 10)
            nickname = nickname.substr(0, 9) + ".";
        std::cout << "|" << std::setw(10) << list;
        std::cout << "|" << std::setw(10) << name;
        std::cout << "|" << std::setw(10) << lastname;
        std::cout << "|" << std::setw(10) << nickname << "|" << std::endl;
        
        list++;
    }
	list = 1;
    std::cout << "|----------|----------|----------|----------|" << std::endl;



	std::cout << "ENTREZ UN NUMERO DE CONTACT" << std::endl;
	std::getline (std::cin, index_str);
	index_int = ft_atoi(index_str);
	if (index_int > 0 && index_int < 9 && _contact[index_int - 1].GetName() != "")
	{
		std::cout << "Name: " << _contact[index_int - 1].GetName() << std::endl;
		std::cout << "Last name: " << _contact[index_int - 1].GetLastName() << std::endl;
		std::cout << "Nickname: " << _contact[index_int - 1].GetNickname() << std::endl;
		std::cout << "Phone number: " << _contact[index_int - 1].GetPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << _contact[index_int - 1].GetDarkestSecret() << std::endl;
		return (1);
	}
	else
		std::cout << "INDEX INVALIDE" << std::endl;
	return (0);
}

static int ft_atoi(std::string str)
{
	int i = 0;
	int res = 0;
	int sign = 1;

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}