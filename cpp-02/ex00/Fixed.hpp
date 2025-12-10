/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*    	this->fractBits = 8;                                            +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:14:38 by gangel-a          #+#    #+#             */
/*   Updated: 2025/12/09 19:20:55 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
private:
	int _value;
	static const int _fractBits = 8;

public:
	Fixed(void);
	Fixed(const Fixed& copy);
	Fixed &operator=(const Fixed& value);
	~Fixed(void);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif