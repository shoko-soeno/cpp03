/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:53:44 by ssoeno            #+#    #+#             */
/*   Updated: 2025/03/20 14:30:35 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string>

class ClapTrap
{
protected:
    static const unsigned int defaultEnergyPoints;  // default energy points is 10
    static const unsigned int defaultHitPoints;     // default hit points is 10
    static const unsigned int defaultAttackDamage;  // default attack damage is 0
        
protected:
    std::string  name;
    unsigned int hitPoints;
    unsigned int energyPoints; // energy points 
    unsigned int attackDamage;

public:
    ClapTrap();
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &src);
    ClapTrap &operator=(const ClapTrap &src);
    virtual ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
