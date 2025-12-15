/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:48:38 by gangel-a          #+#    #+#             */
/*   Updated: 2025/11/25 18:48:20 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class Zombie {
private:
	std::string	_name;
public:
	Zombie(void);
	~Zombie(void);
	void	announce(void) const;
	void	setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
