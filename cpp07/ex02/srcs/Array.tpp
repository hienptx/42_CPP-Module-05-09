/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:00:13 by hipham            #+#    #+#             */
/*   Updated: 2025/03/20 13:47:32 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

template <typename T>
Array<T>::Array(): n(MAX_VAL), arr(new T[MAX_VAL])
{
	// std::cout << "A constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(int num): n(num), arr(new T[num])
{
	// std::cout << "Parameterized constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array<T>& src)
{
	// std::cout << "Copy constructor called" << std::endl;
	n = src.n;
	arr = new T[n];
	for (int i = 0; i < n; i++)
		arr[i] = src.arr[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T>& src)
{
	// std::cout << "Assignment constructor called" << std::endl;
	if (this != &src)
	{
		delete[] arr;
		n = src.n;
		arr = new T[n];
		for (int i = 0; i < n; i++)
			arr[i] = src.arr[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete [] arr;
	// std::cout << "Array Deconstructor called" << std::endl;
}

template <typename T>
int Array<T>::size()
{
	return (n);
}

template <typename T>
T &Array<T>::operator[](const int idx)
{
	if (idx < 0 || idx > n)
		throw std::out_of_range("Index is out of bound");
	return arr[idx];
}