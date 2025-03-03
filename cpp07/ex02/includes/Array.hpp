/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:06:39 by hipham            #+#    #+#             */
/*   Updated: 2025/03/03 18:10:18 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
	private:
		int	n;
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
// template <typename T>
// int Array<T>::size()
// {
// 	return (n);
// }

// template <typename T>
// T &Array<T>::operator[](const int idx)
// {
// 	return arr[idx];
// }

// template <typename T>
// Array<T>::Array(): n(10), arr(new T[10])
// {
// 	std::cout << "A constructor called" << std::endl;
// }

// template <typename T>
// Array<T>::Array(int num): n(num), arr(new T[num])
// {
// 	std::cout << "Parameterized constructor called" << std::endl;
// }

// template <typename T>
// Array<T>::Array(const Array& src): n(src.n), arr(src.arr)
// {
// 	std::cout << "Copy constructor called" << std::endl;
// }

// template <typename T>
// Array<T> &Array<T>::operator=(const Array& src)
// {
// 	std::cout << "Assignment constructor called" << std::endl;
// 	if (this != &src)
// 	{
// 		n = src.n;
// 		arr = src.arr;
// 	}
// 	return (*this);
// }

// template <typename T>
// Array<T>::~Array()
// {
// 	std::cout << "Array Deconstructor called" << std::endl;
// }

#endif