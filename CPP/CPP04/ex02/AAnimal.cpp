/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 03:06:34 by vgodart           #+#    #+#             */
/*   Updated: 2025/02/18 03:06:41 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"


AAnimal::AAnimal() : _type("AAnimal")
{
    std::cout << "AAnimal default constuctor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) : _type(copy._type)
{
    std::cout << "AAnimal copy constuctor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &copy)
{
    if ( this != &copy )
    {
        _type = copy._type;
    }
    std::cout << "AAnimal assignation operator called" << std::endl;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
    return _type;
}
