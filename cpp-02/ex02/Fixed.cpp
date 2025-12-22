/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:19:30 by gangel-a          #+#    #+#             */
/*   Updated: 2025/12/22 17:29:53 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
	// std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int value) {
	// std::cout << "Int constructor called" << std::endl;

	int fixedValue = value << _fractBits;
	this->setRawBits(fixedValue);
}

Fixed::Fixed(const float value) {
	// std::cout << "Float constructor called" << std::endl;

	float fixedValue = value * (1 << _fractBits);
	this->setRawBits((int)roundf(fixedValue));
}

Fixed::Fixed(const Fixed& copy) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed& other) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

Fixed::~Fixed(void) {
	// std::cout << "Destructor called" << std::endl;
}

bool Fixed::operator>(const Fixed& other) const {
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const {
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const {
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const {
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const {
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const {
	return (this->getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed n(this->toFloat() + other.toFloat());
	return n;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed n(this->toFloat() - other.toFloat());
	return n;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed n(this->toFloat() * other.toFloat());
	return n;
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed n(this->toFloat() / other.toFloat());
	return n;
}

Fixed& Fixed::operator++(void) {
	int newValue = this->getRawBits() + 1;
	this->setRawBits(newValue);

	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed oldValue(*this);
	this->setRawBits(this->getRawBits() + 1);

	return oldValue;
}

Fixed& Fixed::operator--(void) {
	int newValue = this->getRawBits() - 1;
	this->setRawBits(newValue);

	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed oldValue(*this);
	this->setRawBits(this->getRawBits() - 1);

	return oldValue;
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

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a > b)
		return b;
	else
		return a;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a > b)
		return b;
	else
		return a;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a < b)
		return b;
	else
		return a;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a < b)
		return b;
	else
		return a;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	std::cout << obj.toFloat();
	return os;
}
