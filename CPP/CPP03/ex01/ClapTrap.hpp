/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 04:54:17 by vgodart           #+#    #+#             */
/*   Updated: 2025/02/13 04:54:19 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const & src);
        virtual ~ClapTrap();
        ClapTrap & operator=(ClapTrap const & src);
        virtual void attack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    protected:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
};

#endif