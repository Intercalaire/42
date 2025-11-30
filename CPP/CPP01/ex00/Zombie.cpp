/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 03:59:19 by vgodart           #+#    #+#             */
/*   Updated: 2024/11/21 03:59:20 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name("Zombie") {
}

Zombie::Zombie(std::string name) : _name(name) {
}

Zombie::~Zombie() {
	std::cout << _name << " is destroyed" << std::endl;
}

void Zombie::announce(void) const {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
