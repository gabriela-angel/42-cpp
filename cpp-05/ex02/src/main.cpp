/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:12:21 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/06 20:05:42 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << "==============================" << std::endl;
	std::cout << "           VARIABLES          " << std::endl;
	std::cout << "==============================" << std::endl;

	Bureaucrat boss("Boss", 1);
	Bureaucrat manager("Manager", 50);
	Bureaucrat intern("Intern", 150);

	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Arthur Dent");

	std::cout << boss << manager << intern << std::endl;
	std::cout << shrub << robot << pardon << std::endl;

	std::cout << "==============================" << std::endl;
	std::cout << "   TEST: execute not signed   " << std::endl;
	std::cout << "==============================" << std::endl;

	boss.executeForm(shrub);
	std::cout << std::endl;

	std::cout << "==============================" << std::endl;
	std::cout << "     TEST: sign failure       " << std::endl;
	std::cout << "==============================" << std::endl;

	intern.signForm(robot);
	std::cout << robot << std::endl;

	std::cout << "==============================" << std::endl;
	std::cout << "     TEST: sign success       " << std::endl;
	std::cout << "==============================" << std::endl;

	manager.signForm(shrub);
	boss.signForm(robot);
	boss.signForm(pardon);

	std::cout << shrub << robot << pardon << std::endl;

	std::cout << "==============================" << std::endl;
	std::cout << "   TEST: execute grade fail   " << std::endl;
	std::cout << "==============================" << std::endl;

	manager.executeForm(robot);
	manager.executeForm(pardon);
	std::cout << std::endl;

	std::cout << "==============================" << std::endl;
	std::cout << "     TEST: execute success    " << std::endl;
	std::cout << "==============================" << std::endl;

	boss.executeForm(shrub);
	boss.executeForm(robot);
	boss.executeForm(pardon);

	return 0;
}
