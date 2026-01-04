/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:39:46 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/04 18:48:40 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Form {
private:
	const std::string	_name;
	bool 				_isSigned;
	const int			_gradeSign;
	const int			_gradeExec;
public:
	Form(std::string name, int grade);
	Form(const Form& copy);
	Form& operator=(const Form& other);
	~Form(void);

	const std::string	getName(void) const;
	bool				getSignStatus(void) const;
	int					getGradeSign(void) const;
	int					getGradeExec(void) const;

	void beSigned(Bureaucrat& obj);

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif