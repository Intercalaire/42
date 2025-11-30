/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 03:08:21 by vgodart           #+#    #+#             */
/*   Updated: 2025/02/18 03:08:23 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        void makeSound() const;
        WrongCat();
        ~WrongCat();
        WrongCat(const WrongCat &copy);
        WrongCat &operator=(const WrongCat &copy);
};

#endif
