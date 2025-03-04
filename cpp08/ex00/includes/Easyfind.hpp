/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:15:14 by hipham            #+#    #+#             */
/*   Updated: 2025/03/04 17:10:40 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &haystack, int needle)
{
	auto result = std::find(haystack.begin(), haystack.end(), needle);
	if (result != haystack.end())
		return result;
	else
		throw std::runtime_error("Not found");
}

#endif