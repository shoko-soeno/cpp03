/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:07:26 by ssoeno            #+#    #+#             */
/*   Updated: 2025/03/20 14:53:35 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

const unsigned int FragTrap::fragDefaultHitPoints = 100;
const unsigned int FragTrap::fragDefaultEnergyPoints = 100;
const unsigned int FragTrap::fragDefaultAttackDamage = 30;

FragTrap::FragTrap() : ClapTrap() {
    hitPoints = fragDefaultHitPoints;
    energyPoints = fragDefaultEnergyPoints;
    attackDamage = fragDefaultAttackDamage;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    hitPoints = fragDefaultHitPoints;
    energyPoints = fragDefaultEnergyPoints;
    attackDamage = fragDefaultAttackDamage;
    std::cout << "FragTrap " << name << " is created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = src;
}

FragTrap:: ~FragTrap() {
    std::cout << "FragTrap " << name << " is destroyed!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src) {
    std::cout << "FragTrap Assignation operator called" << std::endl;
    if (this != &src) {
        ClapTrap::operator=(src);
    }
    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if (energyPoints <= 0)
    {
        std::cout << "FragTrap " << name << " is out of energy and cannot attack!" << std::endl;
        return ;
    } else if (hitPoints <= 0)
    {
        std::cout << "FragTrap " << name << " is dead!" << std::endl;
        return ;
    } else {
        std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " says high fives guys!" << std::endl;
}
