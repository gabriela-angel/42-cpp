/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:12:21 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/06 18:08:52 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	{
		std::cout << "==============================" << std::endl;
		std::cout << "       TEST: constructor      " << std::endl;
		std::cout << "==============================" << std::endl;
		try {
			Form a("TooHigh", 0, 0);
		}
		catch (std::exception& e) {
			std::cout << "Error creating Form TooHigh: " << e.what() << std::endl;
		}

		try {
			Form b("TooLow", 151, 151);
		}
		catch (std::exception& e) {
			std::cout << "Error creating Form TooLow: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "==============================" << std::endl;
		std::cout << "     TEST: valid limits       " << std::endl;
		std::cout << "==============================" << std::endl;

		try {
			Form min("MinGrades", 1, 1);
			Form max("MaxGrades", 150, 150);
			std::cout << min << max << std::endl;
		}
		catch (std::exception& e) {
			std::cout << "Unexpected error: " << e.what() << std::endl;
		}
	}
	std::cout << "==============================" << std::endl;
	std::cout << "           VARIABLES          " << std::endl;
	std::cout << "==============================" << std::endl;
	
	Bureaucrat harry("Harry", 1);
	Bureaucrat steve("Steve", 50);
	Form importantDoc("Contrato Importante", 1, 30);
	Form ordinaryDoc("Contrato Comum", 60, 100);
	
	std::cout << harry << steve << importantDoc << ordinaryDoc << std::endl;
	{
		std::cout << "==============================" << std::endl;
		std::cout << "        TEST: failure        " << std::endl;
		std::cout << "==============================" << std::endl;
		steve.signForm(importantDoc);
		std::cout << importantDoc << std::endl;
	}
	{
		std::cout << "==============================" << std::endl;
		std::cout << "         TEST: success        " << std::endl;
		std::cout << "==============================" << std::endl;
		harry.signForm(importantDoc);
		steve.signForm(ordinaryDoc);
		std::cout << importantDoc << ordinaryDoc << std::endl;
	}
	{
		std::cout << "==================================" << std::endl;
		std::cout << "     TEST: form already signed    " << std::endl;
		std::cout << "==================================" << std::endl;
		harry.signForm(ordinaryDoc);
		std::cout << std::endl;
	}
	{
		std::cout << "==============================" << std::endl;
		std::cout << "    TEST: direct beSigned     " << std::endl;
		std::cout << "==============================" << std::endl;

		Bureaucrat low("Low", 100);
		Form f("DirectSign", 50, 50);

		try {
			f.beSigned(low);
		}
		catch (std::exception& e) {
			std::cout << "Expected failure: " << e.what() << std::endl;
		}

		std::cout << f << std::endl;
	}
	return 0;
}
