/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:18:31 by gangel-a          #+#    #+#             */
/*   Updated: 2025/12/18 15:27:09 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_atkDmg = 30;

	std::cout << "FragTrap default constructor called for \"" << this->_name << "\"" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {
	std::cout << "FragTrap copy constructor called for \"" << this->_name << "\"" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "FragTrap copy assignment operator called for \"" << this->_name << "\"" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap destructor called for \"" << this->_name << "\"" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0 || this->_energyPoints == 0)
		std::cout << "FlagTrap " << this->_name << " cannot attack " << target << std::endl;
	else {
		std::cout << "FlagTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_atkDmg << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FlagTrap " << this->_name << " asks for a high-five" << std::endl;
}
