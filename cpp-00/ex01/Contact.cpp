/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 20:26:38 by gangel-a          #+#    #+#             */
/*   Updated: 2025/09/06 20:31:27 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void){}

std::string Contact::getFirstName(void) const {
	return this->_firstName;
}

std::string Contact::getLastName(void) const {
	return this->_lastName;
}

std::string Contact::getNickname(void) const {
	return this->_nickname;
}

std::string Contact::getPhoneNumber(void) const {
	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret(void) const {
	return this->_darkestSecret;
}

bool Contact::_checkPhoneNumber(std::string phoneNumber) {
	if (!std::isdigit(phoneNumber[0]) && phoneNumber[0] != '+') {
		std::cout << "Invalid phone number: phone number must start with a number or '+'.\n";
		return (false);
	}
	if (phoneNumber.length() > 15) {
		std::cout << "Invalid phone number: phone number is too long.\n";
		return (false);
	}
	for (int i = 1; phoneNumber[i]; i++) {
		if (!std::isdigit(phoneNumber[i])) {
			std::cout << "Invalid phone number: phone number must contain only digits.\n";
			return (false);
		}
	}
	return (true);
}

int Contact::modifyContact(std::string firstName,
	std::string lastName, std::string nickname,
	std::string phoneNumber, std::string darkestSecret){

	if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty()) {
		std::cout << "All fields must be filled.\n";
		return (1);
	}
	if (_checkPhoneNumber(phoneNumber) == false)
		return (1);
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickname;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;

	std::cout << "Contact has been added.\n";
	return (0);
}

Contact::~Contact(void){}