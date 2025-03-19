/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:22:29 by hipham            #+#    #+#             */
/*   Updated: 2025/03/19 15:10:17 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

/*
reinterpret_cast is a type of casting in C++ that is used for low-level pointer conversions. It allows:

Converting a pointer into an integer type (uintptr_t)
Converting an integer type back into a pointer
Casting between unrelated pointer types
💡 It does not modify the actual memory, but simply changes how the data is interpreted.
*/

#include <iostream>

struct Data
{
    int num[3] = {9, 2, 0};
    char c = 'A';
    std::string s = "Hello world";
};

class Serializer
{
    private:
       Serializer() = delete;
       Serializer(const Serializer&) = delete;
       Serializer &operator=(const Serializer&) = delete;
       ~Serializer() = delete;
    public: 
       static uintptr_t serialize(Data* ptr);
       static Data* deserialize(uintptr_t raw); 
};

#endif