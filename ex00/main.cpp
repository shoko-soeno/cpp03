/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:30:55 by ssoeno            #+#    #+#             */
/*   Updated: 2025/03/18 21:36:39 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main() {
    ClapTrap claptrap("CL4P-TP");

    claptrap.attack("Moulinex");
    claptrap.takeDamage(3);
    claptrap.beRepaired(5);
    claptrap.attack("Moulinex Beta");
    claptrap.takeDamage(12);
    claptrap.attack("Moulinex 2.0");
    return 0;
}
