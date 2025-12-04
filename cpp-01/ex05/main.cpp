/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:39:37 by gangel-a          #+#    #+#             */
/*   Updated: 2025/12/04 17:13:33 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl customer;

	customer.complain("DEBUG");
	customer.complain("INFO");
	customer.complain("WARNING");
	customer.complain("ERROR");
	customer.complain("HELLO");
	customer.complain("");
	
	return 0;
}
