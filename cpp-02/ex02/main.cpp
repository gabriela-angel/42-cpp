/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:24:01 by gangel-a          #+#    #+#             */
/*   Updated: 2025/12/22 17:25:18 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;
	}
	{
		Fixed a;
		Fixed b(10);
		Fixed c(42.42f);
		Fixed d(b);

		std::cout << "a (default): " << a << std::endl;
		std::cout << "b (int):     " << b << std::endl;
		std::cout << "c (float):   " << c << std::endl;
		std::cout << "d (copy b):  " << d << std::endl;

		a = Fixed(5.5f);
		std::cout << "a (assigned): " << a << std::endl;

		std::cout << "c as int   : " << c.toInt() << std::endl;
		std::cout << "c as float : " << c.toFloat() << std::endl;
	}
	{
		Fixed x(3);
		Fixed y(7);

		std::cout << "x = " << x << ", y = " << y << std::endl;
		std::cout << "x > y  : " << (x > y) << std::endl;
		std::cout << "x < y  : " << (x < y) << std::endl;
		std::cout << "x >= y : " << (x >= y) << std::endl;
		std::cout << "x <= y : " << (x <= y) << std::endl;
		std::cout << "x == y : " << (x == y) << std::endl;
		std::cout << "x != y : " << (x != y) << std::endl;
	}
	{
		Fixed p(5.5f);
		Fixed q(2);

		std::cout << "p = " << p << ", q = " << q << std::endl;
		std::cout << "p + q = " << (p + q) << std::endl;
		std::cout << "p - q = " << (p - q) << std::endl;
		std::cout << "p * q = " << (p * q) << std::endl;
		std::cout << "p / q = " << (p / q) << std::endl;
	}
	{
		Fixed inc(1);

		std::cout << "inc      : " << inc << std::endl;
		std::cout << "++inc    : " << ++inc << std::endl;
		std::cout << "inc      : " << inc << std::endl;

		std::cout << "inc++    : " << inc++ << std::endl;
		std::cout << "inc      : " << inc << std::endl;

		std::cout << "--inc    : " << --inc << std::endl;
		std::cout << "inc      : " << inc << std::endl;

		std::cout << "inc--    : " << inc-- << std::endl;
		std::cout << "inc      : " << inc << std::endl;
	}
	{
		Fixed m1(10);
		Fixed m2(20);

		std::cout << "min(m1, m2) : " << Fixed::min(m1, m2) << std::endl;
		std::cout << "max(m1, m2) : " << Fixed::max(m1, m2) << std::endl;

		const Fixed cm1(42.42f);
		const Fixed cm2(21.21f);

		std::cout << "min(const)  : " << Fixed::min(cm1, cm2) << std::endl;
		std::cout << "max(const)  : " << Fixed::max(cm1, cm2) << std::endl;
	}
	return 0;
}
