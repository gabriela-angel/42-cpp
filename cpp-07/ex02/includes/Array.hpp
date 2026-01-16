/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:46:01 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/16 17:13:35 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class Array {
private:
	T* _data;
	unsigned int _size;
public:
	Array();
	Array(unsigned int n);
	Array(const Array& copy);
	Array& operator=(const Array& other);
	T& operator[](int index);
	const T& operator[](int index) const;
	~Array();

	unsigned int size(void) const;

	class IndexOutOfBounds : public std::exception {
		public:
			const char *what() const throw();
	};
};

#endif