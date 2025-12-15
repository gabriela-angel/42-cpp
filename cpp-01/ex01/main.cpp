/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:48:42 by gangel-a          #+#    #+#             */
/*   Updated: 2025/11/25 19:53:17 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie* horde = zombieHorde(5, "Zombie");

	for (int i = 0; i < 5; i++) {
		std::cout << "Zombie no. " << i + 1 << ":" << std::endl;
		horde[i].announce();
	}
		
	delete[] horde;
	return 0;
}
