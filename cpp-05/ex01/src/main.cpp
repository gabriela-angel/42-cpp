/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:12:21 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/04 18:37:17 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << "==============================" << std::endl;
		std::cout << "       TEST: constructor      " << std::endl;
		std::cout << "==============================" << std::endl << std::endl;
		try {
			Bureaucrat a("TooHigh", 0);
		}
		catch (std::exception& e) {
			std::cout << "Error creating TooHigh: " << e.what() << std::endl;
		}

		try {
			Bureaucrat b("TooLow", 151);
		}
		catch (std::exception& e) {
			std::cout << "Error creating TooLow: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	
	Bureaucrat harry("Harry", 1);
	Bureaucrat steve("Steve", 150);

	{
		std::cout << "==============================" << std::endl;
		std::cout << "        TEST: failures        " << std::endl;
		std::cout << "==============================" << std::endl;
		std::cout << std::endl << "Before changes:" << std::endl
		<< harry << steve;
		try {
			harry.incrementGrade();
		}
		catch (std::exception& e)
		{
			std::cout << "Increment " << harry.getName() << " failed: "
			<< e.what() << std::endl;
		}
	
		try {
			steve.decrementGrade();
		}
		catch (std::exception& e)
		{
			std::cout << "Decrement " << steve.getName() << " failed: "
			<< e.what() << std::endl;
		}
		std::cout << std::endl << "After changes (failed):" << std::endl
		<< harry << steve << std::endl;
	}
	{
		std::cout << "==============================" << std::endl;
		std::cout << "         TEST: success        " << std::endl;
		std::cout << "==============================" << std::endl;
		std::cout << std::endl << "Before changes:" << std::endl
		<< harry << steve;
		try {
			harry.decrementGrade();
			steve.incrementGrade();
		}
		catch (std::exception& e)
		{
			std::cout << "Unexpected error: " << e.what() << std::endl;
		}
		std::cout << std::endl << "After changes:" << std::endl
		<< harry << steve << std::endl;
	}
	return 0;
}
