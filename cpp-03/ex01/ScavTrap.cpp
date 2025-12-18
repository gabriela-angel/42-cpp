/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:36:59 by gangel-a          #+#    #+#             */
/*   Updated: 2025/12/18 15:10:56 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_atkDmg = 20;

	std::cout << "ScavTrap default constructor called for \"" << this->_name << "\"" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {
	std::cout << "ScavTrap copy constructor called for \"" << this->_name << "\"" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap copy assignment operator called for \"" << this->_name << "\"" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor called for \"" << this->_name << "\"" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0 || this->_energyPoints == 0)
		std::cout << "ScavTrap " << this->_name << " cannot attack " << target << std::endl;
	else {
		std::cout << "ScavTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_atkDmg << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->_name << "is now guarding the gate" << std::endl;
}