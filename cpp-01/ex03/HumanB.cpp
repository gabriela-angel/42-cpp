/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:14:11 by gangel-a          #+#    #+#             */
/*   Updated: 2025/11/25 21:15:47 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->_name = name;
}

void HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}

void HumanB::attack(void) const {
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " has no weapon!" << std::endl;
}

HumanB::~HumanB (void) {}