/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:42:21 by gangel-a          #+#    #+#             */
/*   Updated: 2025/12/04 17:39:41 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl (void) {}

void Harl::debug( void ){
	std::cout << "[DEBUG]: I love having extra bacon on my 7XL-double-cheese-triple-pickle-ketchup-special burger. I really love it!" << std::endl;
}

void Harl::info( void ){
	std::cout << "[INFO]: I can't believe adding extra bacon costs more money. You didn't put enough bacon on my burger! If you had, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void ){
	std::cout << "[WARNING]: I think I deserve to have extra bacon for free. I've been coming here for years, while you only started working here last month." << std::endl;
}

void Harl::error( void ){
	std::cout << "[EROOR]: This is unacceptable! I want to speak to the manager right now." << std::endl;
}

void Harl::complain(std::string level) {
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*harlFuncs[4])(void);
	
	harlFuncs[0] = &Harl::debug;
	harlFuncs[1] = &Harl::info;
	harlFuncs[2] = &Harl::warning;
	harlFuncs[3] = &Harl::error;

	int index;
	index = -1;
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level)
			index = i;
	}

	switch (index)
	{
		case 0:
			(this->*harlFuncs[0])();
			// fall through
		case 1:
			(this->*harlFuncs[1])();
			// fall through
		case 2:
			(this->*harlFuncs[2])();
			// fall through
		case 3:
			(this->*harlFuncs[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

Harl::~Harl (void) {}
