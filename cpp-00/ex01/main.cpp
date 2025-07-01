/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:07:03 by gangel-a          #+#    #+#             */
/*   Updated: 2025/07/01 15:01:07 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.class.hpp"

int	main(void)
{
	Contact		contacts[8];
	PhoneBook	phonebook(contacts);
	std::string	cmd;
	int i = 0;

	while (true)
	{
		std::cout << "Enter a command from the following list [ADD, SEARCH, EXIT]: ";
		std::cin >> cmd;
		if (cmd.compare("ADD") == 0)
		{
			std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
			std::cout << "\nFirst name: ";
			std::cin >> firstName;
			std::cout << "\nLast name: ";
			std::cin >> lastName;
			std::cout << "\nNickname: ";
			std::cin >> nickName;
			std::cout << "\nPhone number: ";
			std::cin >> phoneNumber;
			std::cout << "\nDarkest secret: ";
			std::cin >> darkestSecret;
			std::cout << std::endl;
			if (i == 8)
				i = 0;
			if (phonebook.contacts[i].modifyContact(firstName, lastName,
				nickName, phoneNumber, darkestSecret) == 0)
				i++;
		}
		else if (cmd.compare("SEARCH") == 0)
		{
			std::cout << "     Index|First name| Last name|  Nickname";
		}
		else if (cmd.compare("EXIT") == 0)
			break ;
	}
	return (0);
}
