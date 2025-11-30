/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:39:56 by vgodart           #+#    #+#             */
/*   Updated: 2024/11/28 16:39:57 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::~Weapon()
{
}

std::string const &Weapon::getType() const
{
	return (_type);
}

void Weapon::setType(std::string type)
{
	_type = type;
}