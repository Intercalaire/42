/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 02:29:23 by vgodart           #+#    #+#             */
/*   Updated: 2025/02/14 02:29:25 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src)
{
    std::cout << "ScavTrap " << src._name <<  " copy constructor called" << std::endl;
    _name = src._name;
    _hitPoints = src._hitPoints;
    _energyPoints = src._energyPoints;
    _attackDamage = src._attackDamage;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & src)
{
    std::cout << "ScavTrap" << _name << " assignation operator called" << std::endl;
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

void    ScavTrap::attack(const std::string& target)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints -= 1;
    }
    else if (_hitPoints <= 0)
    {
        std::cout << "ScavTrap " << _name << " is dead and cannot attack" << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << _name << " is out of energy and cannot attack" << std::endl;
    }
}

void ScavTrap::guardGate()
{
    if (_hitPoints <= 0)
    {
        std::cout << "ScavTrap " << _name << " is dead and cannot guard the gate" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << _name << " have enterred in Gate keeper mode" << std::endl;
}
