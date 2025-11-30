/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 03:59:09 by vgodart           #+#    #+#             */
/*   Updated: 2024/11/28 15:27:43 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Address of the string: " << &str << std::endl;
    std::cout << "Address of the stringPTR: " << stringPTR << std::endl;
    std::cout << "Address of the stringREF: " << &stringREF << std::endl;

    std::cout << "value of String: " << str << std::endl;
    std::cout << "value of StringPTR: " << *stringPTR << std::endl;
    std::cout << "value of StringREF: " << stringREF << std::endl;

    return (0);
}
