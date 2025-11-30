/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:42:17 by vgodart           #+#    #+#             */
/*   Updated: 2025/02/24 16:42:19 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = "";
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = other._ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain assignation operator called" << std::endl;
    if (this == &other)
        return *this;
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = other._ideas[i];
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}