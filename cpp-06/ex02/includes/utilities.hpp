/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:52:42 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/13 14:20:22 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_HPP
# define UTILITIES_HPP

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <string>
# include <cstdlib>
# include <ctime>
# include <iostream>

Base* createA(void);
Base* createB(void);
Base* createC(void);
	
Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif