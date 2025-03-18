/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:30:55 by ssoeno            #+#    #+#             */
/*   Updated: 2025/03/18 15:41:47 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
    Fixed a; // default constructor called (initializes as 0)
    // 5.05 * 2 = 10.1016
    Fixed const b(Fixed(5.05f) * Fixed(2));

    // operator overload test
    std::cout << a << std::endl;
    // prefix increment: internally increments the fixed-point value by 1
    // so the value is now 0.00390625(1/256)
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    // 0.00390625 + 0.00390625 = 0.0078125
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    // b = 10.1016
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}

/*
$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>

Fixed const b(Fixed(5.05f) * Fixed(2));
Fixed(5.05f)
5.05 * 256 = 1292.8 -> 1293
Fixed(2)
2 * 256 = 512

Asterisk operator(overloaded) is called:
Fixed(5.05f) * Fixed(2) = 1293 * 512 = 662016
662016 >> 8 = 662016 / 256 = 2587

oveloaded << operator is called:
std::cout << b << std::endl;
b = 2587 / 256 = 10.1016
*/

