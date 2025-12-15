/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:07:03 by gangel-a          #+#    #+#             */
/*   Updated: 2025/09/06 20:50:59 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	cmd;

	while (true)
	{
		std::cout << "Enter a command from the following list [ADD, SEARCH, EXIT]: ";
		std::cin >> cmd;
		std::cin.ignore();
		if (cmd.compare("ADD") == 0)
		{
			std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
			std::cout << "First name: ";
			std::getline(std::cin, firstName);
			std::cout << "Last name: ";
			std::getline(std::cin, lastName);
			std::cout << "Nickname: ";
			std::getline(std::cin, nickname);
			std::cout << "Phone number: ";
			std::getline(std::cin, phoneNumber);
			std::cout << "Darkest secret: ";
			std::getline(std::cin, darkestSecret);
			std::cout << std::endl;
			phonebook.addContact(firstName, lastName,
				nickname, phoneNumber, darkestSecret);
		}
		else if (cmd.compare("SEARCH") == 0)
		{
			phonebook.displayContacts();
			phonebook.requestIndex();
		}
		else if (cmd.compare("EXIT") == 0)
			break ;
	}
	return (0);
}
