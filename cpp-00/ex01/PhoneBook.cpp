/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:13:45 by gangel-a          #+#    #+#             */
/*   Updated: 2025/09/06 21:48:26 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	this->_index = 0;
	this->_totalContacts = 0;
}

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
		return str.substr(0,9) + ".";
	return str;
}

void PhoneBook::displayContacts(void) const {
	if (this->_totalContacts == 0)
		std::cout << "No contacts were added to the list." << std::endl;
	else {
		std::cout << std::setw(10) << std::right << "Index" << "|";
		std::cout << std::setw(10) << std::right << "First name" << "|";
		std::cout << std::setw(10) << std::right << "Last name" << "|";
		std::cout << std::setw(10) << std::right << "Nickname" << std::endl;
		for (int i = 0; i < this->_totalContacts; i++)
		{
			std::cout << std::setw(10) << std::right << i + 1 << "|";
			std::cout << std::setw(10) << std::right << _truncate(_contacts[i].getFirstName()) << "|";
			std::cout << std::setw(10) << std::right << _truncate(_contacts[i].getLastName()) << "|";
			std::cout << std::setw(10) << std::right << _truncate(_contacts[i].getNickname()) << std::endl;
		}
	}
}

void PhoneBook::requestIndex(void) const {
	int			index;

	if (this->_totalContacts == 0)
		return ;

	while (true)
	{
		std::cout << "Select an index: ";
		std::cin >> index;

		if (std::cin.fail() || index > this->_totalContacts || index < 1)
		{
			std::cin.clear(); // reset fail state
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush input
			std::cout << "Invalid input." << std::endl;
		}
		else {
			_getContactInfo(index - 1);
			break;
		}
	}
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
