/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:41:26 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/11 20:06:02 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>
# include <cctype>
# include <limits>

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();
	
	static bool isInt(std::string literal);
	static bool isChar(std::string literal);
	static bool isFloat(std::string literal);
	static bool isDouble(std::string literal);

	static void toInt(std::string literal);
	static void toChar(std::string literal);
	static void toFloat(std::string literal);
	static void toDouble(std::string literal);

	static void handlePseudoLiteral(std::string literal);
	static void printConversion(char c, int n, float f, double d, std::string err);
	static bool checkOverflow(long double ld, std::string type);

public:
	static void convert(std::string literal);
};

#endif