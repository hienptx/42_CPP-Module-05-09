/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:00:19 by hipham            #+#    #+#             */
/*   Updated: 2025/03/19 15:15:08 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

/* reinterpret_cast will force the compiler to make a conversion, period. Even if it theoretically cant be done
    It does 4 things:
    - retyping references
    - retyping pointers
    - obtaining an address out of a pointer (or building a pointer from an address)
    - same type conversion (which does nothing)
*/

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
