/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:50:17 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/13 14:52:45 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.hpp"

Base* createA(void) {
	return new A();
}

Base* createB(void) {
	return new B();
}

Base* createC(void) {
	return new C();
}

Base * generate(void) {
	Base* (*createTypes[3])(void) = {
		&createA,
		&createB,
		&createC
	};

	// Seed the random number generator once
	srand(static_cast<unsigned int>(time(0)));
	// Generate a random number in the range [min, max]
	// (rand() % (max - min + 1)) + min;
	int n = (rand() % (2 + 1));
	Base *ret = (*createTypes[n])();
	
	return ret;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type: C" << std::endl;
	else
		std::cout << "Type: not identified" << std::endl;
	return;
}

// Using pointer dynamic_cast to avoid exception-based control flow
void identify(Base& p) {
	if (dynamic_cast<A*>(&p))
		std::cout << "Type: A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "Type: B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "Type: C" << std::endl;
	else
		std::cout << "Type: not identified" << std::endl;

	return;
}