/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:24:20 by gangel-a          #+#    #+#             */
/*   Updated: 2025/12/18 22:43:22 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const Cat& copy) : Animal(copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain(*copy._brain);
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assignment called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

void Cat::makeSound(void) const {
	std::cout << "Meow. Mreeeow meow. *HISS* " << std::endl;
}

const Brain* Cat::getBrain() const {
	return this->_brain;
}