/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:36:54 by gangel-a          #+#    #+#             */
/*   Updated: 2026/02/02 19:36:45 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span& copy) {
	*this = copy;
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_v = other._v;
		_N = other._N;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int toAdd) {
	if (_v.size() < _N)
		_v.push_back(toAdd);
	else
		throw std::logic_error("Cannot add more items to the object");
}

int Span::shortestSpan() {
	if (_v.size() < 2)
		throw std::logic_error("Not enough elements to calculate span");
	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	int min_diff;

	for (size_t i = 0; i < tmp.size() - 1; i++) {
		int current_diff = std::abs(tmp[i + 1] - tmp[i]);
		if (i == 0 || current_diff < min_diff)
			min_diff = current_diff;
		if (min_diff == 0)
			return 0;
	}
	
	return min_diff;
}

int Span::longestSpan() {
	if (_v.size() < 2)
		throw std::logic_error("Not enough elements to calculate span");
	int min = *(std::min_element(_v.begin(), _v.end()));
	int max = *(std::max_element(_v.begin(), _v.end()));
	return std::abs(max - min);
}