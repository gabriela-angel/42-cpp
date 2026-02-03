/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:42:52 by gangel-a          #+#    #+#             */
/*   Updated: 2026/02/02 19:34:25 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <exception>

int main(void) {
	std::cout << "==== SUBJECT TEST ====" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n==== ITERATOR TEST ====" << std::endl;
	try {
		Span sp(10);
		std::vector<int> v;

		for (int i = 0; i < 10; i++)
			v.push_back(i * 10);

		sp.addNumber(v.begin(), v.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n==== 10K TEST ====" << std::endl;
	try {
		const unsigned int size = 10000;
		Span sp(size);
		std::vector<int> big;

		for (unsigned int i = 0; i < size; i++)
			big.push_back(i);

		sp.addNumber(big.begin(), big.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n==== EXCEPTION TEST ====" << std::endl;
	try {
		Span sp(1);
		sp.addNumber(42);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
	}
	catch (std::exception& e) {
		std::cout << "Expected exception: " << e.what() << std::endl;
	}

	return 0;
}