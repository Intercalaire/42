/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:17:16 by vgodart           #+#    #+#             */
/*   Updated: 2025/03/19 23:17:19 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SERIALIZER_HPP
	#define	SERIALIZER_HPP

#include 	<iostream>
#include	<stdint.h>

struct Data
{
	unsigned int	id;
	std::string		message;
};

class Serializer{
	public:

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
	
		Serializer();
		Serializer(const Serializer &copy);
		Serializer& operator=(const Serializer&);
		~Serializer();

};

#endif