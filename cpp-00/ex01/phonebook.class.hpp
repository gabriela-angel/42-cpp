/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:03:33 by gangel-a          #+#    #+#             */
/*   Updated: 2025/07/01 15:00:37 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_h

# include <iostream>
# include <string>

class	Contact {
public:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	Contact(void);
	~Contact(void);

	int modifyContact(std::string firstName,
		std::string lastName, std::string nickname,
		std::string phoneNumber, std::string darkestSecret);
};

class	PhoneBook {
public:
	Contact	contacts[8];

	PhoneBook(Contact list_contact[8]);
	~PhoneBook(void);
};

#endif