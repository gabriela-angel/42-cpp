/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:23:15 by gangel-a          #+#    #+#             */
/*   Updated: 2026/02/02 19:35:30 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <algorithm>

class Span {
private:
	std::vector<int> _v;
	unsigned int _N;
public:
	Span();
	Span(unsigned int N);
	Span(const Span& copy);
	Span& operator=(const Span& other);
	~Span();

	int shortestSpan();
	int longestSpan();
	void addNumber(int toAdd);
	
	template <typename It>
	void addNumber(It begin, It end) {
		size_t dist = std::distance(begin, end);
		if (_v.size() + dist > _N)
			throw std::logic_error("Cannot add all items to the object");

		_v.insert(_v.end(), begin, end);
	}
};

#endif