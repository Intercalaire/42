/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:42:22 by vgodart           #+#    #+#             */
/*   Updated: 2025/02/24 16:42:24 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
    public:
    Brain();
    Brain(const Brain &other);
    Brain &operator=(const Brain &other);
    ~Brain();
    std::string _ideas[100];
};

#endif

