/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:23:15 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/21 17:18:35 by gangel-a         ###   ########.fr       */
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

	void addNumber(int toAdd);
	int shortestSpan();
	int longestSpan();
	// add multiple elements function
};

#endif