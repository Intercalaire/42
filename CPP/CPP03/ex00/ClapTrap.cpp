/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 04:54:06 by vgodart           #+#    #+#             */
/*   Updated: 2025/02/13 04:54:13 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
    std::cout << "ClapTrap " << src._name <<  " copy constructor called" << std::endl;
    _name = src._name;
    _hitPoints = src._hitPoints;
    _energyPoints = src._energyPoints;
    _attackDamage = src._attackDamage;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &src) {
    std::cout << "ClapTrap assignation operator called" << std::endl;
    if (this != &src) {
        _name = src._name;
        _hitPoints = src._hitPoints;
        _energyPoints = src._energyPoints;
        _attackDamage = src._attackDamage;
    }
    return *this;
}

void    ClapTrap::attack(const std::string& target)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints -= 1;
    }
    else if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " is dead and cannot attack" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " is out of energy and cannot attack" << std::endl;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
        if (amount >= _hitPoints)
        {
            _hitPoints = 0;
            std::cout << "ClapTrap " << _name << " is dead" << std::endl;
        }
        else
        {
            _hitPoints -= amount;
        }
        std::cout << "ClapTrap " << _name << " has " << _hitPoints << " hit points left" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is dead and cannot be repaired" << std::endl;
        return ;
    }
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is out of energy and cannot be repaired" << std::endl;
        return ;
    }
    if (amount > _energyPoints)
    {
        std::cout << "ClapTrap " << _name << " does not have enough energy to be repaired" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _name << " is being repaired for " << amount << " hit points" << std::endl;
    _hitPoints += amount;
    _energyPoints -= amount;
    std::cout << "ClapTrap " << _name << " has " << _hitPoints << " hit points left" << std::endl;
}