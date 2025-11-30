/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 01:55:14 by vgodart           #+#    #+#             */
/*   Updated: 2025/06/25 01:55:17 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("default target")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	if (target.empty())
		throw std::invalid_argument("Target cannot be an empty string");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other), _target(other._target)
{

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		_target = other._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLowException();

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}