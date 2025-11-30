/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 03:06:34 by vgodart           #+#    #+#             */
/*   Updated: 2025/02/18 03:06:41 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


Animal::Animal() : _type("Animal")
{
    std::cout << "Animal default constuctor called" << std::endl;
}

Animal::Animal(const Animal &copy) : _type(copy._type)
{
    std::cout << "Animal copy constuctor called" << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
    if ( this != &copy )
    {
        _type = copy._type;
    }
    std::cout << "Animal assignation operator called" << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return _type;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}
