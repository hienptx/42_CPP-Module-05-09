/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:37:47 by hipham            #+#    #+#             */
/*   Updated: 2025/02/20 15:30:00 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
		std::cout << "Invalid input. Ony one argument is accepted" << std::endl;
	return 0;
}
