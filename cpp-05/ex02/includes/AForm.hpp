/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:39:46 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/06 19:24:05 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string	_name;
	bool 				_isSigned;
	const int			_gradeSign;
	const int			_gradeExec;
protected:
    void				checkExecution(Bureaucrat const & executor) const;
public:
	AForm(void);
	AForm(std::string name, int gradeSign, int gradeExec);
	AForm(const AForm& copy);
	AForm& operator=(const AForm& other);
	virtual ~AForm(void);

	const std::string&	getName(void) const;
	bool				getSignStatus(void) const;
	int					getGradeSign(void) const;
	int					getGradeExec(void) const;

	void				beSigned(Bureaucrat& obj);
	virtual void		execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};
	class FormNotSigned : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif