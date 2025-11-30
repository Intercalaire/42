/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 01:54:58 by vgodart           #+#    #+#             */
/*   Updated: 2025/06/25 01:55:00 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("default target")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	if (target.empty())
		throw std::invalid_argument("Target cannot be an empty string");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), _target(other._target)
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		_target = other._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLowException();

	std::cout << "* drilling noises *" << std::endl;
	
	// Initialize random seed
	static bool seeded = false;
	if (!seeded) {
		std::srand(std::time(NULL));
		seeded = true;
	}
	
	// 50% chance of success
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy on " << _target << " failed!" << std::endl;
}
