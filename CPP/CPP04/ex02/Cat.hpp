/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 03:07:27 by vgodart           #+#    #+#             */
/*   Updated: 2025/02/18 03:07:29 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    public:
        Cat();
        Cat(const Cat &copy);
        Cat &operator=(const Cat &copy);
        ~Cat();
        void makeSound() const;
    private:
        Brain *_brain;
    
};

#endif