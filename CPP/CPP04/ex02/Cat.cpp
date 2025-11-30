/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 03:07:32 by vgodart           #+#    #+#             */
/*   Updated: 2025/02/18 03:07:33 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    _type = "Cat";
    _brain = new Brain();
    std::cout << "Cat constuctor called" << std::endl;
}

Cat::Cat(const Cat &copy) : AAnimal(copy)
{
    _type = copy._type;
    _brain = new Brain(*copy._brain);
    std::cout << "Cat copy constuctor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
    if ( this != &copy )
    {
        AAnimal::operator=(copy);
        delete _brain;
        _brain = new Brain(*copy._brain);
        _type = copy._type;
    }
    std::cout << "Cat assignation operator called" << std::endl;
    return *this;
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}