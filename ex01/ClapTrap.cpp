/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:16:58 by ssoeno            #+#    #+#             */
/*   Updated: 2025/03/20 14:31:10 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

const unsigned int ClapTrap::defaultEnergyPoints = 10;
const unsigned int ClapTrap::defaultHitPoints = 10;
const unsigned int ClapTrap::defaultAttackDamage = 0;

ClapTrap::ClapTrap() : name("Default") {
    std::cout << "ClapTrap Default constructor called" << std::endl;
    this->hitPoints = defaultHitPoints;
    energyPoints = defaultEnergyPoints;
    attackDamage = defaultAttackDamage;
}

ClapTrap::ClapTrap(const std::string &name) : name(name) {
    std::cout << "ClapTrap " << name << " is alive and ready for action!" << std::endl;
    hitPoints = defaultHitPoints;
    energyPoints = defaultEnergyPoints;
    attackDamage = defaultAttackDamage;
}

ClapTrap::ClapTrap(const ClapTrap &src){
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src){
    std::cout << "ClapTrap Assignation operator called" << std::endl;
    if (this != &src) {
        this->name = src.name;
        this->hitPoints = src.hitPoints;
        this->energyPoints = src.energyPoints;
        this->attackDamage = src.attackDamage;
    }
    return *this;
}
// should use throw an error if self-assignment is attempted

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap " << name << " is destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " is out of energy and cannot attach!" << std::endl;
        return ;
    } else if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " is dead!" << std::endl;
        return ;
    } else {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
        return ;
    }
    if (hitPoints <= amount)
    {
        std::cout << "ClapTrap " << name << " is dead!" << std::endl;
        hitPoints = 0;
        return ;
    }
    if (hitPoints > amount)
    {
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
        hitPoints -= amount;
        std::cout << "ClapTrap " << name << " now has " << hitPoints << " hit points left!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount){
    if (energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " is out of energy and cannot be repaired!" << std::endl;
        return ;
    }
    hitPoints += amount;
    energyPoints--;
    std::cout << "ClapTrap " << name << " now has " << hitPoints << " hit points!" << std::endl;
}
