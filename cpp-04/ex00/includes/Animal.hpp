/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:40:05 by gangel-a          #+#    #+#             */
/*   Updated: 2025/12/18 20:44:22 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
protected:
	std::string	type;

public:
	Animal(void);
	Animal(std::string type);
	Animal(const Animal& copy);
	Animal& operator=(const Animal& other);
	
	// Without virtual: the base function runs, even if the object is from a child class.
	// With virtual: the child's version runs, like you expect.
	virtual ~Animal(void);

	virtual void makeSound(void) const;
	const std::string getType(void) const;
};

#endif