/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:42:45 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/13 14:50:56 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "utilities.hpp"

int main(void) {
	Base *testPTR = generate();
	Base *testREF = generate();
	
	std::cout << "testPTR: ";
	identify(testPTR);

	std::cout << "testREF: ";
	identify(*testREF);

	delete testPTR;
	delete testREF;
}