/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:37:47 by hipham            #+#    #+#             */
/*   Updated: 2025/02/24 19:56:38 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int main()
{
	Data x;
	Data *u;
	uintptr_t y;
	
	y = Serializer::serialize(&x);
	std::cout << "Serialized: " << y << std::endl;
	
	u = Serializer::deserialize(y);
	std::cout << "Deserialized: " << u->c << std::endl;
	std::cout << "Deserialized: " << u->num << std::endl;
	std::cout << "Deserialized: " << u->s << std::endl;
	return 0;
}
