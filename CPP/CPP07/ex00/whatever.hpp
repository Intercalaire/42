/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:17:16 by vgodart           #+#    #+#             */
/*   Updated: 2025/03/19 23:17:19 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>


template <typename T>
T min(T a, T b)
{
	return (a < b) ? a : b;
}

template <typename T>
T max(T a, T b)
{
	return (a > b) ? a : b;
}

template <typename T>
void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}	


#endif