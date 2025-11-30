/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 03:06:44 by vgodart           #+#    #+#             */
/*   Updated: 2025/02/18 03:06:47 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
    public:
        Animal();
        Animal(const Animal &copy);
        Animal &operator=(const Animal &copy);
        virtual ~Animal();
        std::string getType() const;
        virtual void makeSound() const;
    protected:
        std::string _type;

};

#endif