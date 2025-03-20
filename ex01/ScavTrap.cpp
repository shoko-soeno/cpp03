/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:07:26 by ssoeno            #+#    #+#             */
/*   Updated: 2025/03/20 14:32:42 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

const unsigned int ScavTrap::scavDefaultHitPoints = 100;
const unsigned int ScavTrap::scavDefaultEnergyPoints = 50;
const unsigned int ScavTrap::scavDefaultAttackDamage = 20;

ScavTrap::ScavTrap() : ClapTrap() {
    hitPoints = scavDefaultHitPoints;
    energyPoints = scavDefaultEnergyPoints;
    attackDamage = scavDefaultAttackDamage;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    hitPoints = scavDefaultHitPoints;
    energyPoints = scavDefaultEnergyPoints;
    attackDamage = scavDefaultAttackDamage;
    std::cout << "ScavTrap " << name << " is created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    *this = src;
}

ScavTrap:: ~ScavTrap() {
    std::cout << "ScavTrap " << name << " is destroyed!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src) {
    std::cout << "ScavTrap Assignation operator called" << std::endl;
    if (this != &src) {
        ClapTrap::operator=(src);
    }
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (energyPoints <= 0)
    {
        std::cout << "ScavTrap " << name << " is out of energy and cannot attach!" << std::endl;
        return ;
    } else if (hitPoints <= 0)
    {
        std::cout << "ScavTrap " << name << " is dead!" << std::endl;
        return ;
    } else {
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << name << " has entered in Gate keeper mode!" << std::endl;
}
