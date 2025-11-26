/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:03:39 by gangel-a          #+#    #+#             */
/*   Updated: 2025/11/25 21:15:36 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {
private:
	std::string _name;
	Weapon* _weapon;

public:
	HumanB(std::string name);
	~HumanB(void);

	void attack(void) const;
	void setWeapon(Weapon& weapon);
};

#endif