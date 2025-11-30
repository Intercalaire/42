/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 22:39:37 by vgodart           #+#    #+#             */
/*   Updated: 2025/07/04 22:39:38 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP 

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>
#include <exception>


class Intern
{
	private:
		AForm *RobotomyRequestForm(const std::string &target) const;
		AForm *PresidentialPardonForm(const std::string &target) const;
		AForm *ShrubberyCreationForm(const std::string &target) const;

	public:
		// Constructors
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();

		// Member functions
		AForm *makeForm(const std::string &formName, const std::string &target) const;

};

#endif 