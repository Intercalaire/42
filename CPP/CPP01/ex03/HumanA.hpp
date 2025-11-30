/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:40:09 by vgodart           #+#    #+#             */
/*   Updated: 2024/11/28 16:40:12 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void attack(void);

	private:
		std::string _name;
		Weapon &_weapon;
};

#endif
