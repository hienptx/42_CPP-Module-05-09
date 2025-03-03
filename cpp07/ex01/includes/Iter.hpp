/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:10:09 by hipham            #+#    #+#             */
/*   Updated: 2025/03/03 13:57:44 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <functional>

template <typename T>
void Iter(T *arr, int len, void (*f)(T&))
{
    int i = 0;
    
    while(i < len)
    {
        f(arr[i]);
        i++;
    }
} 

template <typename T>
void print_element(const T &element)
{   
    std::cout << element << std::endl;
}

#endif