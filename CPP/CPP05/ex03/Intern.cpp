/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 22:39:40 by vgodart           #+#    #+#             */
/*   Updated: 2025/07/04 22:39:43 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>


Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{

}

AForm* Intern::RobotomyRequestForm(const std::string &target) const
{
	return new ::RobotomyRequestForm(target);
}

AForm* Intern::PresidentialPardonForm(const std::string &target) const
{
	return new ::PresidentialPardonForm(target);
}

AForm* Intern::ShrubberyCreationForm(const std::string &target) const
{
	return new ::ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const
{
	AForm* (Intern::*targetlist[])(const std::string&) const = {
		&Intern::RobotomyRequestForm,
		&Intern::PresidentialPardonForm,
		&Intern::ShrubberyCreationForm
	};
	std::string list[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	for (int i = 0; i < 3; ++i)
	{
		if (list[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*targetlist[i])(target);
		}
	}
	std::cout << "Error: Form \"" << formName << "\" does not exist" << std::endl;
	return NULL;
}
