/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:57:05 by gangel-a          #+#    #+#             */
/*   Updated: 2025/11/25 20:45:28 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->_type = type;
}

const std::string& Weapon::getType(void) const{
	return this->_type;
}

void Weapon::setType(std::string type) {
	this->_type = type;
}

Weapon::~Weapon(void) {}