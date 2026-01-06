/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 21:45:48 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/06 18:06:55 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("default"), _isSigned(false), _gradeSign(150), _gradeExec(150) {}

AForm::AForm(std::string name, int gradeSign, int gradeExec) : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec){
	if (gradeSign < 1 || gradeExec < 1)
			throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
			throw GradeTooLowException();
}

AForm::AForm(const AForm& copy) : _name(copy.getName()), _isSigned(copy.getSignStatus()), _gradeSign(copy.getGradeSign()), _gradeExec(copy.getGradeExec()) {}

AForm& AForm::operator=(const AForm& other) {
	std::cout << "The use of an assignment operator for this class is invalid. Each Aform is unique and unchangeable." << std::endl;
	(void)other;
	return *this;
}

AForm::~AForm(void) {}

void AForm::checkExecution(Bureaucrat const & executor) const {
	if (!this->getSignStatus())
		throw FormNotSigned();
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
}

const std::string& AForm::getName(void) const {
	return _name;
}

bool AForm::getSignStatus(void) const {
	return _isSigned;
}

int AForm::getGradeSign(void) const {
	return _gradeSign;
}

int AForm::getGradeExec(void) const {
	return _gradeExec;
}

void AForm::beSigned(Bureaucrat& obj) {
	if (obj.getGrade() > _gradeSign)
		throw GradeTooLowException();
	if (this->getSignStatus() == false)
		this->_isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
	os << "Form " << obj.getName() << 
	":\n\tSign Grade:\t" << obj.getGradeSign() <<
	"\n\tExec Grade:\t" << obj.getGradeExec() <<
	"\n\tIs signed:\t" << obj.getSignStatus() << std::endl;
	return os;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const char* AForm::FormNotSigned::what() const throw() {
	return "Form is not signed";
}
