/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 03:59:24 by vgodart           #+#    #+#             */
/*   Updated: 2024/11/21 03:59:25 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
	std::string _name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce(void) const;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
