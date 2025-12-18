/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:33:36 by gangel-a          #+#    #+#             */
/*   Updated: 2025/12/18 14:16:08 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void) {
	ClapTrap trap("Spikey");
	ClapTrap trapTwo("Lanny");
	
	trap.attack("robust enemy");
	trap.takeDamage(4);
	trap.beRepaired(3);
	
	trap.attack("robust enemy");
	trap.attack("tiny enemy");
	trap.takeDamage(2);
	trap.beRepaired(2);
	
	trap.attack("robust enemy");
	trapTwo.attack("tiny enemy");
	trap.takeDamage(2);

	trapTwo.attack("robust enemy");
	trap.attack("tiny enemy");
	trapTwo.takeDamage(10);
	
	trap.attack("boss enemy");
	trap.attack("robust enemy");
	trap.attack("tiny enemy");
	trap.takeDamage(6);

	trap.attack("boss enemy");
	trap.takeDamage(2);
	
	trap.attack("boss enemy");
	trap.takeDamage(6);
	trap.beRepaired(3);

	return 0;
}