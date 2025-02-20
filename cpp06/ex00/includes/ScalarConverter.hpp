/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:39:46 by hipham            #+#    #+#             */
/*   Updated: 2025/02/20 16:59:23 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cctype>

/* "A static member function is a unique function that belongs to the class as a whole,
and not a specific instance. They can be called without the creation of objects of
a class and come with a sea of benefits."  */

class ScalarConverter
{
	public:
		ScalarConverter() = delete; // Prevent instantition
		static int convert(std::string const input);
};

#endif
