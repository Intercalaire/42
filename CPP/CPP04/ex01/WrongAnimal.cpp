/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 03:08:06 by vgodart           #+#    #+#             */
/*   Updated: 2025/02/18 03:08:09 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << "WrongAnimal default constuctor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : _type(copy._type)
{
    std::cout << "WrongAnimal copy constuctor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
    if ( this != &copy )
    {
        _type = copy._type;
    }
    std::cout << "WrongAnimal assignation operator called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return _type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;
}
