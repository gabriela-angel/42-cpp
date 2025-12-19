/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:39:19 by gangel-a          #+#    #+#             */
/*   Updated: 2025/12/18 23:22:17 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j; //should not create a leak
		delete i;
	}
	std::cout << std::endl;
	{
		std::cout  << "*********************************" << std::endl;
		std::cout << "*                                *" << std::endl;
		std::cout << "*           ARRAY TEST           *" << std::endl;
		std::cout << "*                                *" << std::endl;
		std::cout << "*********************************" << std::endl << std::endl;
		Animal* animals[4];

		animals[0] = new Dog();
		animals[1] = new Cat();
		animals[2] = new Dog();
		animals[3] = new Cat();

		for (int i = 0; i < 4; i++)
			delete animals[i];
	}
	std::cout << std::endl;
	{
		std::cout  << "*********************************" << std::endl;
		std::cout << "*                                *" << std::endl;
		std::cout << "*          POINTER TEST          *" << std::endl;
		std::cout << "*                                *" << std::endl;
		std::cout << "*********************************" << std::endl << std::endl;

		Dog dog1;
		Dog dog2(dog1); // copy constructor

		std::cout << "Dog1 brain: " << dog1.getBrain() << std::endl;
		std::cout << "Dog2 brain: " << dog2.getBrain() << std::endl;

		if (dog1.getBrain() == dog2.getBrain())
			std::cout << "❌ SHALLOW COPY DETECTED\n";
		else
			std::cout << "✅ DEEP COPY CONFIRMED\n";
	}
	return 0;
}
