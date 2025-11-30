/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 03:08:26 by vgodart           #+#    #+#             */
/*   Updated: 2025/02/18 03:08:27 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    _type = "WrongCat";
    std::cout << "WrongCat constuctor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
    _type = copy._type;
    std::cout << "WrongCat copy constuctor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
    if ( this != &copy )
    {
        WrongAnimal::operator=(copy);
        _type = copy._type;
    }
    std::cout << "WrongCat assignation operator called" << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}