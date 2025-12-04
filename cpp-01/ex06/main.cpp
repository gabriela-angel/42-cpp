/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:39:37 by gangel-a          #+#    #+#             */
/*   Updated: 2025/12/04 17:21:55 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl customer;

	if (argc != 2) {
		std::cout << "Error: Wrong format. Try: ./harlFilter <level>" << std::endl;
		return 1;
	}
	customer.complain(argv[1]);
	
	return 0;
}
