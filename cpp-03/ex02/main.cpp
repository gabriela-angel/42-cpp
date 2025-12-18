/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:33:36 by gangel-a          #+#    #+#             */
/*   Updated: 2025/12/18 15:26:36 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main (void) {
	ScavTrap trap("Lennard");

	trap.attack("enemy");
	trap.guardGate();
	
	FragTrap trapTwo("Bonnie");

	trapTwo.attack("enemy");
	trapTwo.highFivesGuys();

	return 0;
}