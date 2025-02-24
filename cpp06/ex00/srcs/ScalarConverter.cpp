/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:14:25 by hipham            #+#    #+#             */
/*   Updated: 2025/02/24 18:20:26 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int matched_case(std::string const type)
{
	
	std::regex characterType ("\\D");
	std::regex integerType ("^[+-]?[0-9]+$");
	std::regex floatType("^[+-]?[0-9]+(\\.[0-9]+)?f$|^[+-]?inff$|nanf$");
	std::regex doubleType ("^[+-]?[0-9]+(\\.[0-9]+$)|^[+-]?inf$|nan$");
	
	// Case: Character literal
	if(std::regex_match(type, characterType) && !isspace(type[0])) return 1;	
	//type int: 0, -42, 42
	if(std::regex_match(type, integerType)) return 2;
	//type double: 0.0, -2.4,  4.2, -inf, +inf, nan
	if(std::regex_match(type, doubleType)) return 2;
	//type float: 0.0f, -4.2f, 4.2f, -inff, +inff, nanf
	if(std::regex_match(type, floatType)) return 2;
	return 0;
}

void convertCharMessage(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: non displayable" << std::endl;
	std::cout << "float: non displayable" << std::endl;
	std::cout << "char: non displayable" << std::endl;
}

void convertMessage(std::string const& input) {
	try {
		int num = std::stoi(input);
        float fnum = std::stof(input);
        double dnum = std::stod(input);
		
        std::cout << "char: ";
        if (num >= 32 && num <= 126)
		std::cout << static_cast<char>(num) << std::endl;
        else
            std::cout << "non displayable" << std::endl;
		std::cout << "int: " << num << std::endl;
        std::cout << "float: " << fnum;
        if (fnum == static_cast<int>(fnum)) std::cout << ".0";
        std::cout << "f" << std::endl;
        std::cout << "double: " << dnum;
        if (dnum == static_cast<int>(dnum)) std::cout << ".0";
        std::cout << std::endl;
    }
    catch (const std::invalid_argument&) {
        std::cout << "Invalid input!" << std::endl;
    }
    catch (const std::out_of_range&) {
		std::cout << "Out of range!" << std::endl;
    }
}

int isPseudo(std::string const &input) {
    std::regex floatPseudoType(R"(^[+-]?(inff|nanf)$)");
    std::regex doublePseudoType(R"(^[+-]?(inf|nan)$)");

    if (std::regex_match(input, floatPseudoType) || std::regex_match(input, doublePseudoType)) {
        std::cout << "char: impossible" << std::endl;        
        std::cout << "int: impossible" << std::endl;

        if (std::regex_match(input, floatPseudoType)) {
            std::cout << "float: " << input << std::endl;
            std::cout << "double: " << input.substr(0, input.size() - 1) << std::endl; // Remove 'f' from nanf/inff
        } else {
            std::cout << "float: " << input << "f" << std::endl;        
            std::cout << "double: " << input << std::endl;
        }
        return 1;
    }
    return 0;
}

void ScalarConverter::convert(std::string const input) {
	std::cout << input << std::endl;
	switch (matched_case(input))
	{
		case 1:
			convertCharMessage(input[0]);
			break;
		case 2:
			if(isPseudo(input))
				;				
			else
				convertMessage(input);
			break;
		default:
			std::cout << "Error: Invalid type\n";
			break;
		}
	}
	