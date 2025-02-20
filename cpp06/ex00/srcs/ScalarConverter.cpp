/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:14:25 by hipham            #+#    #+#             */
/*   Updated: 2025/02/20 17:45:33 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

void return_error_sms(std::string str) {
	std::cout << "Error: ";
	std::cout << str << std::endl;
}

int invalid_input(std::string const input) {
	int i = 0;

	if (input.empty())
		return return_error_sms("Input is empty"), 1;
	while (input[i] && isspace(input[i]))
		i++;
	if (input[i] == '\0')
		return return_error_sms("Input contains only non displayable"), 1;
	return 0;
}

std::string trim_space(std::string str) {
	int i = 0;

	while(str[i] && isspace(str[i]))
		i++;
	return(str.erase(0, i));
}

int ScalarConverter::convert(std::string const input) {
	std::string str = input;

	if(invalid_input(input))
		return (1);
	str = trim_space(str);
	std::cout << str << std::endl;
	return 0;
}
