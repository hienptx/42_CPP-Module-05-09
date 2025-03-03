/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:00:13 by hipham            #+#    #+#             */
/*   Updated: 2025/03/03 18:09:41 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

template <typename T>
int Array<T>::size()
{
	return (n);
}

template <typename T>
T &Array<T>::operator[](const int idx)
{
	return arr[idx];
}

template <typename T>
Array<T>::Array(): n(10), arr(new T[10])
{
	std::cout << "A constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(int num): n(num), arr(new T[num])
{
	std::cout << "Parameterized constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array& src): n(src.n), arr(src.arr)
{
	std::cout << "Copy constructor called" << std::endl;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array& src)
{
	std::cout << "Assignment constructor called" << std::endl;
	if (this != &src)
	{
		n = src.n;
		arr = src.arr;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Array Deconstructor called" << std::endl;
}
