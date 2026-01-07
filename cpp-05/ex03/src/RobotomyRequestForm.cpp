/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:31:14 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/06 19:41:16 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy) {
	*this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& other){
	if (this != &other) {
		this->_target = other.getTarget();
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget(void) const {
	return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	checkExecution(executor);
	
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	int n = std::rand();

	std::cout << "*tzZZz* *tzzZZzz* ... *clank* ... *CLANK**CLANK**CLANK*" << std::endl;
	if ((n % 2) == 0)
		std::cout << getTarget() << " was successfully robotomized!" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}

