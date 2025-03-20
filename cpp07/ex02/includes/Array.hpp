/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:06:39 by hipham            #+#    #+#             */
/*   Updated: 2025/03/20 13:23:52 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#define MAX_VAL 10

template <typename T>
class Array
{
	private:
		int		n;
		T		*arr;
	public:
		Array();
		Array(int num);
		Array(const Array& src);
		Array &operator=(const Array& src);
		~Array();

		int size();
		T &operator[](const int idx);
};

#include "../srcs/Array.tpp"

#endif