/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:39:46 by vgodart           #+#    #+#             */
/*   Updated: 2024/11/28 16:39:48 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();
		std::string const &getType() const;
		void setType(std::string type);
	private:
		std::string _type;
};

#endif
