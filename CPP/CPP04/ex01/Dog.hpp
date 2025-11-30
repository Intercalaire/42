/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 03:07:21 by vgodart           #+#    #+#             */
/*   Updated: 2025/02/18 03:07:23 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog &copy);
        Dog &operator=(const Dog &copy);
        ~Dog();
        void makeSound() const;
    private:
        Brain *_brain;
};

#endif
