/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:17:16 by vgodart           #+#    #+#             */
/*   Updated: 2025/03/19 23:17:19 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename Function>
void iter(T *array, std::size_t size, Function function)
{
	if (!array || size == 0 || !function)
		return;

	for (std::size_t i = 0; i < size; i++)
		function(array[i]);
}

template <typename T>
void printElement(const T &element)
{
	std::cout << element << std::endl;
}

template <typename T>
void printArray(const T *array, std::size_t size)
{
	if (!array || size < 2)
	{
		std::cout << "Array invalid or too small" << std::endl;
		return;
	}
	std::cout << "[" << array[0] << ", " << array[1] << "]" << std::endl;
}

template <typename T>
void doubleValue(T &element)
{
	element *= 2;
}

template <typename T>
void incrementValue(T &element)
{
	element++;
}

template <typename T>
void toUpperCase(char &c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 'a' + 'A';
}
#endif