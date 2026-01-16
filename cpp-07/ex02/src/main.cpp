/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:52:30 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/16 17:27:01 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"
#include <iostream>

void printTitle(const std::string& title) {
	std::cout << "\n==== " << title << " ====\n";
}

int main() {

	printTitle("DEFAULT CONSTRUCTOR");
	Array<int> empty;
	std::cout << "Size: " << empty.size() << std::endl;

	printTitle("SIZE CONSTRUCTOR (int)");
	Array<int> a(5);
	std::cout << "Size: " << a.size() << std::endl;
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << "a[" << i << "] = " << a[i] << std::endl;

	printTitle("OPERATOR []");
	a[0] = 10;
	a[1] = 20;
	a[2] = 30;
	std::cout << a[0] << ", " << a[1] << ", " << a[2] << std::endl;

	printTitle("OUT OF BOUNDS");
	try {
		std::cout << a[100] << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	printTitle("COPY CONSTRUCTOR");
	Array<int> copy(a);
	copy[0] = 999;
	std::cout << "Original: " << a[0] << ", " << a[1] << ", " << a[2] << ", " << a[3] << ", " << a[4] << std::endl;
	std::cout << "Copy: " << copy[0] << ", " << copy[1] << ", " << copy[2] << ", " << copy[3] << ", " << copy[4] << std::endl;

	printTitle("ASSIGNMENT OPERATOR");
	Array<int> assigned;
	assigned = a;
	assigned[1] = 888;
	std::cout << "Original: " << a[0] << ", " << a[1] << ", " << a[2] << ", " << a[3] << ", " << a[4] << std::endl;
	std::cout << "Assigned: " << assigned[0] << ", " << assigned[1] << ", " << assigned[2] << ", " << assigned[3] << ", " << assigned[4] << std::endl;

	printTitle("CONST CHECK");
	const Array<int> constArray(a);
	std::cout << "Const size: " << constArray.size() << std::endl;
	std::cout << "Const access: " << constArray[0] << std::endl;

	return 0;
}
