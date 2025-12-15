/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:19:30 by gangel-a          #+#    #+#             */
/*   Updated: 2025/12/14 15:22:15 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;

	int fixedValue = value;
	for (int i = 0; i < this->_fractBits; i++) {
		fixedValue = fixedValue * 2;
	}

	this->setRawBits(fixedValue);
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;

	float fixedValue = value;
	for (int i = 0; i < this->_fractBits; i++) {
		fixedValue = fixedValue * 2;
	}

	this->setRawBits((int)roundf(fixedValue));
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	
	return os;
}

int Fixed::getRawBits(void) const {
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}