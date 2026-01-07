/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:07:23 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/07 18:26:20 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
private:
    AForm* createRobotomyRequestForm(std::string target);
    AForm* createPresidentialPardonForm(std::string target);
    AForm* createShrubberyCreationForm(std::string target);
public:
    Intern(void);
    Intern(const Intern& copy);
    Intern& operator=(const Intern& other);
    ~Intern(void);

    AForm* makeForm(std::string name, std::string target);
};

#endif
