/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:39:46 by hipham            #+#    #+#             */
/*   Updated: 2025/02/24 20:13:00 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cctype>
#include <regex>
#include <exception>

/* "A static member function is a unique function that belongs to the class as a whole,
and not a specific instance. They can be called without the creation of objects of
a class and come with a sea of benefits."  */

class ScalarConverter
{
	private:
		ScalarConverter() = delete; // Prevent instantition
		ScalarConverter(const ScalarConverter&) = delete;
		ScalarConverter &operator=(const ScalarConverter&) = delete;
		~ScalarConverter() = delete;
	public:
		static void convert(std::string const input);
};

#endif
