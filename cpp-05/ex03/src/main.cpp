/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:12:21 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/07 18:38:47 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main(void)
{
	std::cout << "==============================" << std::endl;
	std::cout << "           VARIABLES          " << std::endl;
	std::cout << "==============================" << std::endl;

	Bureaucrat boss("Boss", 1);
	Bureaucrat manager("Manager", 50);
	Bureaucrat worker("Worker", 140);

	Intern intern;

	AForm* shrub;
	AForm* robot;
	AForm* pardon;
	AForm* invalid;

	shrub = intern.makeForm("shrubbery creation", "home");
	robot = intern.makeForm("robotomy request", "Bender");
	pardon = intern.makeForm("presidential pardon", "Arthur Dent");
	invalid = intern.makeForm("random form", "Nobody");

	std::cout << std::endl;

	std::cout << "==============================" << std::endl;
	std::cout << "         TEST: signing        " << std::endl;
	std::cout << "==============================" << std::endl;

	if (shrub)
		worker.signForm(*shrub);
	if (robot)
		manager.signForm(*robot);
	if (pardon)
		boss.signForm(*pardon);

	std::cout << std::endl;

	std::cout << "==============================" << std::endl;
	std::cout << "     TEST: execute failure    " << std::endl;
	std::cout << "==============================" << std::endl;

	if (shrub)
		worker.executeForm(*shrub);
	if (robot)
		manager.executeForm(*robot);
	if (pardon)
		manager.executeForm(*pardon);

	std::cout << std::endl;

	std::cout << "==============================" << std::endl;
	std::cout << "     TEST: execute success    " << std::endl;
	std::cout << "==============================" << std::endl;

	if (shrub)
		boss.executeForm(*shrub);
	if (robot)
		boss.executeForm(*robot);
	if (pardon)
		boss.executeForm(*pardon);

	delete shrub;
	delete robot;
	delete pardon;
	delete invalid;

	return 0;
}
