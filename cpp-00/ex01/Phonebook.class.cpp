/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:13:45 by gangel-a          #+#    #+#             */
/*   Updated: 2025/07/03 15:00:20 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.class.hpp"

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

int Contact::modifyContact(std::string firstName,
	std::string lastName, std::string nickname,
	std::string phoneNumber, std::string darkestSecret){

	if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty()) {
		std::cout << "All fields must be filled.\n";
		return (1);
	}
	if (_checkPhoneNumber(phoneNumber) == false) {
		std::cout << "Invalid phone number.\n";
		return (1);
	}
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickname;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;

	std::cout << "Contact has been added.\n";
	return (0);
}

Contact::~Contact(void){}

PhoneBook::PhoneBook(void){
	this->_index = 0;
	this->_totalContacts = 0;
}

//add rule to get proper phone number
void PhoneBook::addContact(std::string firstName,
	std::string lastName, std::string nickname,
	std::string phoneNumber, std::string darkestSecret) {
	if (_contacts[this->_index].modifyContact(firstName, lastName,
				nickname, phoneNumber, darkestSecret) == 0) {
		this->_index += 1;
		if (this->_index > 7)
			this->_index = 0;
		if (this->_totalContacts < 8)
			this->_totalContacts += 1;
	}
}

std::string PhoneBook::_truncate(std::string str) const {
	if (str.length() > 10)
		return str.substr(0,8) + ".";
	return str;
}

void PhoneBook::displayContacts(void) const {
	if (this->_index - 1 < 0)
		std::cout << "No contacts were added to the list." << std::endl;
	else {
		std::cout << "     Index|First name| Last name|  Nickname" << std::endl;
		for (int i = 0; i < this->_totalContacts; i++)
		{
			std::cout << i << "|"; // REMEMBER TO RIGHT-ALIGN E FILE 10 SPACES
			std::cout << _truncate(_contacts[i].getFirstName()) << "|";
			std::cout << _truncate(_contacts[i].getLastName()) << "|";
			std::cout << _truncate(_contacts[i].getNickname()) << std::endl;
		}
	}
}

void PhoneBook::requestIndex(void) const {
	std::string	input;
	int			index;
	if (this->_index - 1 < 0)
		return ;
	std::cout << "Select an index: ";
	std::cin >> input;
	std::stringstream ss(input);
	ss >> index;

	if (ss.fail() || index > this->_totalContacts || index < 0)
		std::cout << "Invalid input!" << std::endl;
	else
		_getContactInfo(index);
}

void PhoneBook::_getContactInfo(int index) const {
	std::cout << "\nContact Details:" << std::endl;
	std::cout << "Name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Surname: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
}

PhoneBook::~PhoneBook(void){}
