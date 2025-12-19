/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:13:53 by gangel-a          #+#    #+#             */
/*   Updated: 2025/12/18 21:32:22 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
private:
	std::string ideas[100];
public:
	Brain(void);
	Brain(const Brain& copy);
	Brain& operator=(const Brain& other);
	~Brain(void);

};

#endif