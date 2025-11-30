/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 03:06:44 by vgodart           #+#    #+#             */
/*   Updated: 2025/02/18 03:06:47 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal
{
    public:
        AAnimal();
        AAnimal(const AAnimal &copy);
        AAnimal &operator=(const AAnimal &copy);
        virtual ~AAnimal();
        std::string getType() const;
        virtual void makeSound() const = 0;
    protected:
        std::string _type;

};

#endif