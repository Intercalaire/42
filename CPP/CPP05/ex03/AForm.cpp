/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:17:11 by vgodart           #+#    #+#             */
/*   Updated: 2025/06/25 01:54:19 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _is_signed(false), _sign_grade(150), _execute_grade(150)
{

}

AForm::AForm(const std::string name, const int sign_grade, const int execute_grade) : _name(name), _is_signed(false), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
	if (sign_grade < 1 || execute_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || execute_grade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _is_signed(other._is_signed), _sign_grade(other._sign_grade), _execute_grade(other._execute_grade)
{

}

AForm &AForm::operator=(const AForm &other)
{
	_is_signed = other._is_signed;
	return (*this);
}

AForm::~AForm()
{
	
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _sign_grade)
		_is_signed = true;
	else
		throw GradeTooLowException();
}


std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getIsSigned() const
{
	return (_is_signed);
}

int AForm::getSignGrade() const
{
	return (_sign_grade);
}

int AForm::getExecuteGrade() const
{
	return (_execute_grade);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}


const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed!");
}

std::ostream &operator<<(std::ostream &os,  AForm const &form)
{
	os << "Name: " << form.getName() << " isSigned: " << form.getIsSigned() << " SignGrade: " << form.getSignGrade() << " ExecuteGrade: " << form.getExecuteGrade() << std::endl;
	return (os);
}
