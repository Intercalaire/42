/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:17:16 by vgodart           #+#    #+#             */
/*   Updated: 2025/03/19 23:17:19 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;
	unsigned int size() const;
	
	private:
		T* _array;
		unsigned int _size;
};


#include "Array.tpp"

#endif