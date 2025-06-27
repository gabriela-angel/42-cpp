/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:07:03 by gangel-a          #+#    #+#             */
/*   Updated: 2025/06/27 18:52:04 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.class.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	Contact		contacts[8];
	std::string	cmd;

	while (!cmd || cmd != "EXIT")
	{
		std::cout << "Enter a command from the following list [ADD, SEARCH, EXIT]: ";
		std::cin >> cmd;
		if (cmd == "ADD")
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
		}
		else if (cmd == "SEARCH")
		{
			std::cout << "Index     |First name|Last name |Nickname  ";

		}
	}
	return (0);
}
