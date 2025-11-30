/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:11:37 by vgodart           #+#    #+#             */
/*   Updated: 2024/12/16 15:11:39 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug()
{
	std::cout << "I love to get extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger.";
	std::cout << " I just love it!" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon cost more money.";
	std::cout << " You don’t put enough! If you did I would not have to ask";
	std::cout << " for it!" << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << " I’ve been coming here for years and you just started ";
	std::cout << "working here last month." << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable, I want to speak to the manager now.";
	std::cout << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*complaints[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
	std::string list[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (list[i] == level)
		{
			(this->*complaints[i])();
			return ;
		}
	}
	std::cout << "Invalid complaint level" << std::endl;
}

