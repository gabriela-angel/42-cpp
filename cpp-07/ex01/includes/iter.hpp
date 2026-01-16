/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:16:20 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/16 15:33:52 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstdlib>

template <typename T>
void iter(T* arr, const std::size_t len, void (*func)(T&)) {
	for (std::size_t i = 0; i < len; i++)
		func(arr[i]);
}

template <typename T>
void iter(const T* arr, const std::size_t len, void (*func)(const T&)) {
	for (std::size_t i = 0; i < len; i++)
		func(arr[i]);
}

#endif