/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:45:24 by vgodart           #+#    #+#             */
/*   Updated: 2025/01/10 15:45:25 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value) {
    std::cout << "Int constructor called" << std::endl;
    _value = value << _bits;
}

Fixed::Fixed(float const value) {
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(value * (1 << _bits));
}

Fixed::Fixed(Fixed const &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &src) {
    std::cout << "Copy assignment operator called" << std::endl;
    _value = src.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

float Fixed::toFloat(void) const {
    return (float)_value / (1 << _bits);
}

int Fixed::toInt(void) const {
    return _value >> _bits;
}


std::ostream &operator<<(std::ostream &o, Fixed const &src) {
    o << src.toFloat();
    return o;
}