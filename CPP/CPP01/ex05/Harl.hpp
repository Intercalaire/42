/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:11:44 by vgodart           #+#    #+#             */
/*   Updated: 2024/12/16 15:11:46 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
	public:
		Harl();
		~Harl();
		void complain(std::string level);
	private:
		void debug();
		void info();
		void warning();
		void error();
};

#endif
