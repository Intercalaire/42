/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:45:20 by vgodart           #+#    #+#             */
/*   Updated: 2025/01/10 15:45:21 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
private:
    int _value;
    static const int _bits = 8;

public:
    Fixed();
    Fixed(int const value);
    Fixed(float const value);
    Fixed(Fixed const &src);
    ~Fixed();
    Fixed &operator=(Fixed const &src);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    static Fixed&   min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed&   max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
    bool operator>(const Fixed &src) const;
    bool operator<(const Fixed &src) const;
    bool operator>=(const Fixed &src) const;
    bool operator<=(const Fixed &src) const;
    bool operator==(const Fixed &src) const;
    bool operator!=(const Fixed &src) const;
    Fixed operator+(const Fixed &src) const;
    Fixed operator-(const Fixed &src) const;
    Fixed operator*(const Fixed &src) const;
    Fixed operator/(const Fixed &src) const;
    Fixed operator++();
    Fixed operator++(int);
    Fixed operator--();
    Fixed operator--(int);


};

std::ostream &operator<<(std::ostream &o, Fixed const &src);

#endif