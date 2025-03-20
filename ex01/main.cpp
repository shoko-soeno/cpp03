/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:30:55 by ssoeno            #+#    #+#             */
/*   Updated: 2025/03/20 13:01:18 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {

    ClapTrap clap("clap");
    ClapTrap defaultClap; //default constructor
    ClapTrap copyClap(clap); //copy constructor
    ClapTrap assignClap = clap; //assignation operator

    std::cout << "===ScavTrap Tests===" << std::endl;
    ScavTrap scav("scav");
    ScavTrap defaultScav; //default constructor
    ScavTrap copyScav(scav); //copy constructor
    ScavTrap assignScav = scav; //assignation operator

    std::cout << "===Actions===" << std::endl;
    scav.attack("Enemy 1");
    scav.takeDamage(1);
    scav.beRepaired(1);
    for (int i = 0; i < 12; i++) {
        scav.attack("Enemy 1");
    }
    scav.guardGate();
    scav.takeDamage(100);
    scav.attack("attack test");
    scav.beRepaired(10);
    scav.guardGate();
    return 0;
}
