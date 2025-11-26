/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:56:32 by gangel-a          #+#    #+#             */
/*   Updated: 2025/11/25 20:45:38 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {
private:
	std::string _type;

public:
	Weapon(std::string type);
	~Weapon(void);

	const std::string& getType(void) const;
	void setType(std::string type);
};

#endif
