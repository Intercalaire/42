
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
