/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:44:59 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/06 19:50:07 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
	if (grade < 1)
			throw GradeTooHighException();
	if (grade > 150)
			throw GradeTooLowException();
	 _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy.getName()), _grade(copy.getGrade()) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->_grade = other.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat(void) {}

const std::string Bureaucrat::getName(void) const {
	return _name;
}

int Bureaucrat::getGrade(void) const {
	return _grade;
}

void Bureaucrat::incrementGrade(void) {
	if ((_grade - 1) < 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade(void){
	if ((_grade + 1) > 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm& form) {
	if (form.getSignStatus() == true) {
		std::cout << form.getName() << " Form is already signed" << std::endl;
		return;
	}
	try {
		form.beSigned(*this);
		std::cout << "Bureaucrat " << this->getName() << " assinou Form " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Bureaucrat " << this->getName() << " não conseguiu assinar Form " << form.getName() << " porque "<< e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const {
	try {
		form.execute(*this);
		std::cout << "Bureaucrat " << this->getName() << " executou Form " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Bureaucrat " << this->getName() << " não conseguiu executar Form " << form.getName() << " porque "<< e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << ", burocrata com classificação " << obj.getGrade() << std::endl;
	return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}