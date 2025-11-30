/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:17:16 by vgodart           #+#    #+#             */
/*   Updated: 2025/03/19 23:17:19 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{

}

Bureaucrat::Bureaucrat(const std::string name, unsigned long grade) : _name(name)
{	
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    std::cout << "Bureaucrat " << _name << " assigned" << std::endl;
    if ( this != &copy )
    {
        this->_grade = copy.getGrade();
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{

}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::promote()
{
    if (_grade > 1)
        _grade--;
    else
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::demote()
{
    if (_grade < 150)
        _grade++;
    else
        throw Bureaucrat::GradeTooLowException();
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high, a bureaucrat cannot have a grade higher than 1");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low, a bureaucrat cannot have a grade lower than 150");
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &other)
{
    os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
    return (os);
}