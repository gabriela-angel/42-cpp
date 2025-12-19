/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:39:19 by gangel-a          #+#    #+#             */
/*   Updated: 2025/12/18 21:03:58 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << "*********************************" << std::endl;
		std::cout << "*                               *" << std::endl;
		std::cout << "*        CORRECT CLASSES        *" << std::endl;
		std::cout << "*                               *" << std::endl;
		std::cout << "*********************************" << std::endl << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		meta->makeSound();
		j->makeSound();
		i->makeSound(); // will output the correct cat sound

		delete meta;
		delete j;
		delete i;
	}
	std::cout << std::endl;
	{
		std::cout  << "*********************************" << std::endl;
		std::cout << "*                               *" << std::endl;
		std::cout << "*         WRONG CLASSES         *" << std::endl;
		std::cout << "*                               *" << std::endl;
		std::cout << "*********************************" << std::endl << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* wrongCat = new WrongCat();
		std::cout << wrongCat->getType() << " " << std::endl;
		meta->makeSound();
		wrongCat->makeSound(); // will output the animal sound

		delete meta;
		delete wrongCat;
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
			animals[i]->makeSound();
		for (int i = 0; i < 4; i++)
			delete animals[i];
	}

	return 0;
}
