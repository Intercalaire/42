/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 04:49:59 by vgodart           #+#    #+#             */
/*   Updated: 2024/08/23 04:50:02 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void ft_toupper(std::string str)
{
	for (size_t i = 0; i < str.length(); i++) {
		std::cout << (char)std::toupper(str[i]);
	}
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else {
		for (int i = 1; i < argc; i++) {
			ft_toupper(argv[i]);
		}
	}
	std::cout << std::endl;
	return (0);
}
