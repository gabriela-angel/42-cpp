/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:19:30 by gangel-a          #+#    #+#             */
/*   Updated: 2025/12/22 17:28:38 by gangel-a         ###   ########.fr       */
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

	int fixedValue = value << _fractBits;
	this->setRawBits(fixedValue);
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;

	float fixedValue = value * (1 << _fractBits);
	this->setRawBits((int)roundf(fixedValue));
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float Fixed::toFloat(void) const {
	float n  = (float)(this->getRawBits()) / (1 << _fractBits);

	return n;
}

int Fixed::toInt(void) const {
	int n = (this->getRawBits()) >> _fractBits;

	return n;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	std::cout << obj.toFloat();
	return os;
}
