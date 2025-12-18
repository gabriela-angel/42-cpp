/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:13:15 by gangel-a          #+#    #+#             */
/*   Updated: 2025/12/18 14:18:47 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _atkDmg(0) {
	std::cout << "Default constructor called for \"" << this->_name << "\"" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
	std::cout << "Copy constructor called for \"" << this->_name << "\"" << std::endl;
	*this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Copy assignment operator called for \"" << this->_name << "\"" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_atkDmg = other._atkDmg;
	}
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor called for \"" << this->_name << "\"" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0 || this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " cannot attack " << target << std::endl;
	else {
		std::cout << "ClapTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_atkDmg << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " is already dead" << std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage";
	if (this->_hitPoints == 0)
		std::cout << " and died";
	std::cout << "!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " cannot be repaired anymore" << std::endl;
		return ;
	}
	else if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " does not have any more energy points to use for repair" << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
	std::cout << "ClapTrap " << this->_name << " spent 1 energy point to repair " << amount << "HP" << std::endl;
}
