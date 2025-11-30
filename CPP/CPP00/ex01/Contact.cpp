/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:11:05 by vgodart           #+#    #+#             */
/*   Updated: 2024/11/14 15:11:07 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() :  _Name(""), _Last_name(""), _Nickname(""), _Phone_number(""), _Darkest_secret("")
{
}

Contact::~Contact()
{
}

void	Contact::SetName(std::string name)
{
	_Name = name;
}

void	Contact::SetLastName(std::string lastname)
{
	_Last_name = lastname;
}

void	Contact::SetNickname(std::string nickname)
{
	_Nickname = nickname;
}

void	Contact::SetPhoneNumber(std::string phone)
{
	_Phone_number = phone;
}

void	Contact::SetDarkestSecret(std::string secret)
{
	_Darkest_secret = secret;
}

std::string Contact::GetName() const
{
	return _Name;
}

std::string Contact::GetLastName() const
{
	return _Last_name;
}

std::string Contact::GetNickname() const
{
	return _Nickname;
}

std::string Contact::GetPhoneNumber() const
{
	return _Phone_number;
}

std::string Contact::GetDarkestSecret() const
{
	return _Darkest_secret;
}