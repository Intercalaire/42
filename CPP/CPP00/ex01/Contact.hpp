/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:11:12 by vgodart           #+#    #+#             */
/*   Updated: 2024/11/18 15:28:02 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class	Contact
{
	public:
		Contact();
		~Contact();
		void SetName(std::string name);
		void SetLastName(std::string lastname);
		void SetNickname(std::string nickname);
		void SetPhoneNumber(std::string phone);
		void SetDarkestSecret(std::string secret);
		std::string GetName() const;
		std::string GetLastName() const;
		std::string GetNickname() const;
		std::string GetPhoneNumber() const;
		std::string GetDarkestSecret() const;
	private:
		std::string _Name;
		std::string _Last_name;
		std::string _Nickname;
		std::string _Phone_number;
		std::string _Darkest_secret;
};

#endif
