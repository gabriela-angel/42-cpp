/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:03:17 by gangel-a          #+#    #+#             */
/*   Updated: 2025/11/25 21:13:50 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {
private:
	std::string _name;
	Weapon& _weapon;

public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA(void);

	void attack(void) const;
};

#endif
