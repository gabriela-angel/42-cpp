/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftReplace.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:03:35 by gangel-a          #+#    #+#             */
/*   Updated: 2025/12/04 14:18:31 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void	ftReplace(std::size_t pos, std::size_t len, std::string& str, std::string& subStr) {
	if (pos > str.length())
		return;

	str.erase(pos, len);
	str.insert(pos, subStr);
}
