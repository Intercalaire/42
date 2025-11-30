/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:49:59 by vgodart           #+#    #+#             */
/*   Updated: 2024/12/02 04:50:02 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	int _value;
	static const int _bits = 8;

public:
	Fixed();
	Fixed(Fixed const &src);
	~Fixed();
	Fixed &operator=(Fixed const &src);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif