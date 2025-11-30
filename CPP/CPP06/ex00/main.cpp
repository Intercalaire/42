/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:17:16 by vgodart           #+#    #+#             */
/*   Updated: 2025/03/19 23:17:19 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return (1);
	}
	if (!isprint(av[1][0]))
	{
		std::cerr << "Invalid input" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);		
	return (0);
}