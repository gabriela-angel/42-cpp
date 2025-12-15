/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:03:33 by gangel-a          #+#    #+#             */
/*   Updated: 2025/11/25 17:59:02 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iomanip>
# include <limits>
# include "Contact.hpp"

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