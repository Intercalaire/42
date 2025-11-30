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
# include <iostream>

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name)
{
    std::cout << "Bureaucrat " << _name << " copy" << std::endl;
    *this = copy;
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
	std::cout << "Bureaucrat Deconstructor for " << _name << " called" << std::endl;
}


Bureaucrat::Bureaucrat(std::string name, size_t grade) : _name(name)
{
    std::cout << "Bureaucrat " << _name << " created" << std::endl;

    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade = grade;
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

void Bureaucrat::incrementGrade()
{
    if (_grade > 1)
        _grade--;
    else
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
    if (_grade < 150)
        _grade++;
    else
        throw Bureaucrat::GradeTooLowException();
}


std::string Bureaucrat::getName() const
{
    return _name;
}

size_t Bureaucrat::getGrade() const
{
    return _grade;
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high, a bureaucrat cannot have a grade higher than 1";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low, a bureaucrat cannot have a grade lower than 150";
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat& copy)
{
    o << "Bureaucrat " << copy.getName() << ", bureaucrat grade " << copy.getGrade();
    return o;
}