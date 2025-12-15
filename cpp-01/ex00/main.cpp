/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:48:42 by gangel-a          #+#    #+#             */
/*   Updated: 2025/11/25 18:34:33 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie*	zombie1 = newZombie("Zombie1");
	
	zombie1->announce();
	randomChump("Zombie2");

	delete zombie1;
	return 0;
}
