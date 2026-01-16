/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:09:12 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/13 13:20:14 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main(void) {
	Data ptr = {"Joe", 25};
	uintptr_t reintPtr = Serializer::serialize(&ptr);

	std::cout << "Original Data address: " << &ptr << std::endl;
	std::cout << "Deserialized         : " << Serializer::deserialize(reintPtr) << std::endl;
}
