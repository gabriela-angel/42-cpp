/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:34:23 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/16 15:43:06 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void printInt(const int& x) {
	std::cout << x << std::endl;
}

void increment(int& x) {
	x++;
}

int main() {
	int arr[] = {1, 2, 3};

	std::cout  << "********************************" << std::endl;
	std::cout << "             TEST 1             " << std::endl;
	std::cout << "          (print array)         " << std::endl;
	std::cout << "*********************************" << std::endl;
	iter(arr, 3, printInt);
	std::cout << std::endl;

	std::cout  << "*********************************" << std::endl;
	std::cout << "              TEST 2             " << std::endl;
	std::cout << "         (increment array)       " << std::endl;
	std::cout << "*********************************" << std::endl;
	iter(arr, 3, increment);
	iter(arr, 3, printInt);
	std::cout << std::endl;

	
	std::cout  << "********************************" << std::endl;
	std::cout << "             TEST 3             " << std::endl;
	std::cout << "          (const array)         " << std::endl;
	std::cout << "*********************************" << std::endl;
	const int carr[] = {4, 5, 6};
	iter(carr, 3, printInt);
}
