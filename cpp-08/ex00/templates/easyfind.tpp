/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:42:39 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/20 19:14:05 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
typename T::const_iterator easyfind(const T& container, int n) {
	typename T::const_iterator ret = std::find(container.begin(), container.end(), n);
	if (ret == container.end())
		throw std::out_of_range("Value not found");
	return ret;
}
