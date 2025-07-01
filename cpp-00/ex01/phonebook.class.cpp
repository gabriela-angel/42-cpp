/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:13:45 by gangel-a          #+#    #+#             */
/*   Updated: 2025/07/01 15:00:32 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.class.hpp"

Contact::Contact(void){

}

int	Contact::modifyContact(std::string firstName,
	std::string lastName, std::string nickname,
	std::string phoneNumber, std::string darkestSecret){

	if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty()) {
		std::cout << "Field must no be empty.\n";
		return (1);
	}
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
	return (0);
}

Contact::~Contact(void){

}

PhoneBook::PhoneBook(Contact list_contact[8]){
	for (int i = 0; i < 8; i++)
		this->contacts[i] = list_contact[i];
}

PhoneBook::~PhoneBook(void){
	return ;
}
