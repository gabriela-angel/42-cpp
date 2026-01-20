/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:23:48 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/20 12:49:02 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	*this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	if (this != &other)
		return *this;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isInt(std::string literal) {
	for (long unsigned int i = 0; i < literal.length(); i++) {
		if (i == 0 && (literal[i] == '+' || literal[i] == '-'))
			i++;
		if (!std::isdigit(literal[i]))
			return false;
	}

	long double ld;
	std::stringstream ss(literal);
	ss >> ld;

	if (!checkOverflow(ld, "int"))
		return false;
	return true;
}

bool ScalarConverter::isChar(std::string literal) {
	if (literal.length() != 1)
		return false;
	if (!std::isprint(literal[0]))
		return false;
	return true;
}

bool ScalarConverter::isFloat(std::string literal) {
	long unsigned int pos = literal.find('.');
	if (pos != std::string::npos) {
		if (literal.find('f') != (literal.length() - 1))
			return false;
		if ((pos != 0 && !isdigit(literal[pos - 1])) && (pos != (literal.length() - 1) && !isdigit(literal[pos + 1])))
			return false;
		for (long unsigned int i = 0; i < (literal.length() - 1); i++) {
			if (i == 0 && (literal[i] == '+' || literal[i] == '-'))
				i++;
			if (!std::isdigit(literal[i]) && i != pos)
				return false;
		}
		long double ld;
		std::stringstream ss(literal);
		ss >> ld;

		if (!checkOverflow(ld, "float"))
			return false;
		return true;
	}
	return false;
}

bool ScalarConverter::isDouble(std::string literal) {
	long unsigned int pos = literal.find('.');

	if (pos != std::string::npos) {
		if ((pos != 0 && !isdigit(literal[pos - 1])) && (pos != (literal.length() - 1) && !isdigit(literal[pos + 1])))
				return false;
	}
	for (long unsigned int i = 0; i < literal.length(); i++) {
		if (i == 0 && (literal[i] == '+' || literal[i] == '-'))
			i++;
		if (!std::isdigit(literal[i]) && pos != i)
			return false;
	}

	long double ld;
	std::stringstream ss(literal);
	ss >> ld;
	
	if (!checkOverflow(ld, "double"))
		return false;
	return true;
}

void ScalarConverter::toInt(std::string literal) {
	long double ld;
	std::stringstream ss(literal);
	ss >> ld;
	std::string err = "";

	if (!checkOverflow(ld, "char"))
		err = "c";
	
	int n = static_cast<int>(ld);

	char c = static_cast<char>(n);
	float f = static_cast<float>(n);
	double d = static_cast<double>(n);
	printConversion(c, n, f, d, err);
}

void ScalarConverter::toChar(std::string literal) {
	char c = literal[0];
	std::string err = "\0";
	int n = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);
	printConversion(c, n, f, d, err);
}

void ScalarConverter::toFloat(std::string literal) {
	long double ld;
	std::stringstream ss(literal);
	ss >> ld;
	std::string err = "";

	if (!checkOverflow(ld, "char"))
		err = "c";
	if (!checkOverflow(ld, "int"))
		err += "i";
	if (!checkOverflow(ld, "double"))
		err += "f";
	
	float f = static_cast<float>(ld);

	char c = static_cast<char>(f);
	int n = static_cast<int>(f);
	double d = static_cast<double>(f);
	printConversion(c, n, f, d, err);
}

void ScalarConverter::toDouble(std::string literal) {
	long double ld;
	std::stringstream ss(literal);
	ss >> ld;
	std::string err = "";

	if (!checkOverflow(ld, "char"))
		err = "c";
	if (!checkOverflow(ld, "int"))
		err += "i";
	if (!checkOverflow(ld, "float"))
		err += "f";
	
	double d = static_cast<double>(ld);

	char c = static_cast<char>(d);
	int n = static_cast<int>(d);
	float f = static_cast<float>(d);
	printConversion(c, n, f, d, err);
	
}

void ScalarConverter::handlePseudoLiteral(std::string literal) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (literal[0] == '+') {
		std::cout <<"float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return;
	}
	else if (literal[0] == '-') {
		std::cout <<"float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return;
	}
	std::cout <<"float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void ScalarConverter::printConversion(char c, int n, float f, double d, std::string err) {
	if (err.find('c') != std::string::npos)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: \'" << c << "\'" << std::endl;
	if (err.find('i') != std::string::npos)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << n << std::endl;
	if (err.find('f') != std::string::npos)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

bool ScalarConverter::checkOverflow(long double ld, std::string type) {
	std::string typesArr[] = {"char", "int", "float", "double"};
	int index = -1;
	
	for (int i = 0; i < 4; i++)
	if (typesArr[i] == type) {
		index = i;
		break;
	}
	
	switch (index) {
		case 0:
			if (ld < 0 || ld > 127)
				return false;
			break;
		case 1:
			if (ld > std::numeric_limits<int>::max() || ld < std::numeric_limits<int>::min()) 
				return false;
			break;
		case 2:
			if (ld > std::numeric_limits<float>::max() || ld < -std::numeric_limits<float>::max())
				return false;
			break;
		case 3:
			if (ld > std::numeric_limits<double>::max() || ld < -std::numeric_limits<double>::max())
				return false;
			break;
		default:
			return false;
			break;
	}

	return true;
}

void ScalarConverter::convert(std::string literal) {
	if (literal == "-inf" || literal == "+inf" || literal == "nan" 
		|| literal == "-inff" || literal == "+inff" || literal == "nanf")
		handlePseudoLiteral(literal);
	else if (isFloat(literal))
		toFloat(literal);
	else if (isInt(literal))
		toInt(literal);
	else if (isDouble(literal))
		toDouble(literal);
	else if (isChar(literal))
		toChar(literal);
	else
		std::cout << "Error: Impossible to print or input not convertable" << std::endl;
	return;
}
