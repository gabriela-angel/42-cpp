/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:21:24 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/20 19:27:16 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>
# include <iterator>

template <typename T>
typename T::const_iterator easyfind(const T& container, int n);

#endif
// https://www.geeksforgeeks.org/cpp/the-c-standard-template-library-stl/