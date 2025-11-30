/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 03:59:24 by vgodart           #+#    #+#             */
/*   Updated: 2024/11/28 15:27:36 by vgodart          ###   ########.fr       */
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
	void setName(std::string name);
	void announce(void) const;
};

Zombie* zombieHorde(int N, std::string name);

#endif
