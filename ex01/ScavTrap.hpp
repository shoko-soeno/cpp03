/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:07:30 by ssoeno            #+#    #+#             */
/*   Updated: 2025/03/20 14:27:56 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCARVTRAP_HPP
# define SCARVTRAP_HPP
# include <iostream>
# include <string>

class ScavTrap : public ClapTrap
{
private:
    static const unsigned int scavDefaultHitPoints;
    static const unsigned int scavDefaultEnergyPoints;
    static const unsigned int scavDefaultAttackDamage;
    
public:
    ScavTrap();
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &src);
    ScavTrap &operator=(const ScavTrap &src);
    ~ScavTrap();

    void attack(const std::string& target);
    void guardGate(void);
};

#endif
