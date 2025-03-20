/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:39:18 by ssoeno            #+#    #+#             */
/*   Updated: 2025/03/20 14:53:40 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
    static const unsigned int fragDefaultHitPoints;
    static const unsigned int fragDefaultEnergyPoints;
    static const unsigned int fragDefaultAttackDamage;
    
public:
    FragTrap();
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &src);
    FragTrap &operator=(const FragTrap &src);
    ~FragTrap();

    void attack(const std::string& target);
    void highFivesGuys(void);
};

#endif
