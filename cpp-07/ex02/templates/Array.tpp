/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:54:44 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/16 17:23:19 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _data(0), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n): _size(n) {
	_data = new T[n]();
}

template <typename T>
Array<T>::Array(const Array<T>& copy) {
	_data = 0;
	*this = copy;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this != &other) {
		delete[] this->_data;
		_size = other.size();
		_data = new T[_size]();
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](int index) {
	if(index > static_cast<int>(_size) || index < 0)
		throw IndexOutOfBounds();
	return _data[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const {
	if(index > static_cast<int>(_size) || index < 0)
		throw IndexOutOfBounds();
	return _data[index];
}

template <typename T>
Array<T>::~Array() {
	delete[] _data;
}

template <typename T>
unsigned int Array<T>::size(void) const {
	return _size;
}

template <typename T>
const char* Array<T>::IndexOutOfBounds::what() const throw() {
	return ("Index out of bounds");
}