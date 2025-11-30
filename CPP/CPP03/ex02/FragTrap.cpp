/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 05:07:33 by vgodart           #+#    #+#             */
/*   Updated: 2025/02/14 05:07:36 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor" << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap " << _name << " constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src)
{
    std::cout << "FragTrap " << src._name <<  " copy constructor called" << std::endl;
    _name = src._name;
    _hitPoints = src._hitPoints;
    _energyPoints = src._energyPoints;
    _attackDamage = src._attackDamage;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & src)
{
    std::cout << "FragTrap " << _name << " assignation operator called" << std::endl;
    if (this != &src)
    {
        ClapTrap::operator=(src);
        _name = src._name;
        _hitPoints = src._hitPoints;
        _energyPoints = src._energyPoints;
        _attackDamage = src._attackDamage;
    }
    return *this;
}

void    FragTrap::highFivesGuys(void)
{
    if (_hitPoints <= 0)
    {
        std::cout << "FragTrap " << _name << " is dead and cannot guard the gate" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << _name << " high fives guys" << std::endl;
}
