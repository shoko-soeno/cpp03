/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:06:42 by ssoeno            #+#    #+#             */
/*   Updated: 2025/03/18 14:45:07 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intVal) {
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = intVal << _fractionalBits;
}
/*
Takes a integer and converts it to the internal fixed-point representation
    multiply the integer by 2^8
    << 8 is equivalent to * 256 (2^8)
*/

Fixed::Fixed(const float floatVal) {
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(floatVal * (1 << _fractionalBits));
}
/*
Takes a float and converts it to the internal fixed-point representation
    multiply the float by 2^8 (1 << _fractionalBits is converted to 256)
    round the result
    roundf() is a function that rounds a float to the nearest integer
    (1 << 8) is equivalent to 256 (2^8)
3.14 * 256 = 803.84 -> 804(rounded) -> 1100100100(binary)
integer part: 11
fractional part: 0010 0100
804/256 = 3.140625
*/

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixedPointValue = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    // std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    // std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
    return (float)_fixedPointValue / (1 << _fractionalBits);
}
/*
Converts the internal fixed-point integer back into a float 
by dividing by 256 (i.e., 2^8).
So if the internal value is 2560, toFloat() returns 2560 / 256 = 10.0.
*/

int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}
/*
Converts the fixed-point number to an integer 
by shifting right by 8 bits, 
effectively discarding the fractional part.
*/

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
/*
allows to output a Fixed object directly (e.g., with std::cout).
This overload uses toFloat() to print a human-readable 
floating-point representation.
*/

