/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:48:38 by gangel-a          #+#    #+#             */
/*   Updated: 2025/11/25 18:33:52 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class Zombie {
private:
	std::string	_name;
public:
	Zombie(std::string name);
	~Zombie(void);
	void	announce(void) const;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
