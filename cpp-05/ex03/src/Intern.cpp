/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:13:30 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/07 18:47:18 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern& copy) {
    *this = copy;
}

Intern& Intern::operator=(const Intern& other) {
    if(this != &other)
        return *this;
    return *this;
}

Intern::~Intern(void) {}

AForm* Intern::createRobotomyRequestForm(std::string target) {
    return new RobotomyRequestForm(target);
}
AForm* Intern::createPresidentialPardonForm(std::string target) {
    return new PresidentialPardonForm(target);
}
AForm* Intern::createShrubberyCreationForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string formTarget) {
    std::string opt[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    AForm* (Intern::*createForms[3])(std::string target);

    createForms[0] = &Intern::createRobotomyRequestForm;
    createForms[1] = &Intern::createPresidentialPardonForm;
    createForms[2] = &Intern::createShrubberyCreationForm;
    
    for (int i = 0; i < 3; i++) {
        if (formName == opt[i]) {
            AForm* form = (this->*createForms[i])(formTarget);
            return form; 
        }
    }
    std::cout << "Tipo de Form \"" << formName << "\" não encontrado" << std::endl;
    return NULL;
}
