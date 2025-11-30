/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 04:06:58 by vgodart           #+#    #+#             */
/*   Updated: 2024/11/21 04:07:00 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie* newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name);
	return (zombie);
}