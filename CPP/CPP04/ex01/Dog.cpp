/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 03:07:16 by vgodart           #+#    #+#             */
/*   Updated: 2025/02/18 03:07:18 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    _type = "Dog";
    _brain = new Brain();
    std::cout << "Dog constuctor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    _type = copy._type;
    _brain = new Brain(*copy._brain);
    std::cout << "Dog copy constuctor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
    if ( this != &copy )
    {
        Animal::operator=(copy);
        delete _brain;
        _brain = new Brain(*copy._brain);
        _type = copy._type;
    }
    std::cout << "Dog assignation operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}