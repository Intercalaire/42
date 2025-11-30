/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 03:08:13 by vgodart           #+#    #+#             */
/*   Updated: 2025/02/18 03:08:15 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &copy);
        WrongAnimal &operator=(const WrongAnimal &copy);
        ~WrongAnimal();
        std::string getType() const;
        void makeSound() const;
    protected:
        std::string _type;
};

#endif
