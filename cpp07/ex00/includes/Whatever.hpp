/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:33:51 by hipham            #+#    #+#             */
/*   Updated: 2025/03/03 13:37:03 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void Swap(T& a, T& b)
{
    T temp;
    
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
T Min(T a, T b)
{
    if (a > b)
        return b;
    else if (a < b)
        return a;
    else
        return b;
}

template <typename T>
T Max(T a, T b)
{
    if (a > b)
        return a;
    else if (a < b)
        return b;
    else
        return b;
}

#endif 