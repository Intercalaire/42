/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:10:59 by vgodart           #+#    #+#             */
/*   Updated: 2024/11/18 15:27:55 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void ADD(void);
		int SEARCH(void);
	private:
		Contact _contact[8];
		int _nbr_added;
};

#endif
