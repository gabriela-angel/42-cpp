/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:03:33 by gangel-a          #+#    #+#             */
/*   Updated: 2025/07/08 12:12:59 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>

class	Contact {
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

	bool _checkPhoneNumber(std::string phoneNumber);
public:
	Contact(void);
	~Contact(void);

	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickname(void) const;
	std::string getPhoneNumber(void) const;
	std::string getDarkestSecret(void) const;
	int modifyContact(std::string firstName,
		std::string lastName, std::string nickname,
		std::string phoneNumber, std::string darkestSecret);
};

class	PhoneBook {
private:
	Contact	_contacts[8];
	int		_index;
	int		_totalContacts;

	void		_getContactInfo(int index) const;
	std::string	_truncate(std::string str) const;
public:

	PhoneBook(void);
	~PhoneBook(void);
	void		addContact(std::string firstName,
		std::string lastName, std::string nickname,
		std::string phoneNumber, std::string darkestSecret);
	void		displayContacts(void) const;
	void		requestIndex(void) const;
};

#endif