/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:41:37 by gangel-a          #+#    #+#             */
/*   Updated: 2025/12/18 22:38:55 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
private:
	Brain* _brain;
public:
	Dog(void);
	Dog(const Dog& copy);
	Dog& operator=(const Dog& other);
	~Dog(void);

	void makeSound(void) const;
	const Brain* getBrain(void) const;
};

#endif