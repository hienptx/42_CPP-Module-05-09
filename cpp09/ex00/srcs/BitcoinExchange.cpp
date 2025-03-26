/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:39:02 by hipham            #+#    #+#             */
/*   Updated: 2025/03/26 18:25:48 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

/*==========OCCF==========*/

BitcoinExchange::BitcoinExchange(){}

// BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
// {

// }

BitcoinExchange::~BitcoinExchange() {}

/*==========OVERLOADING OPERATORS==========*/

// BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
// {
// }


/*==========MEMBER FUNCTIONS==========*/

int BitcoinExchange::parse_input(std::ifstream &input)
{
    std::string		line;
	size_t			is_pipe;
	std::string		key;
	double			value;
	bool			first = true;
    std::regex 		first_line(R"(^data\s*\|\s*value$)");
	
    while(std::getline(input, line))
	{
		if (first)
		{
			if(std::regex_match(line, first_line))
				return std::cerr << "Error: Wrong format\n", 0;
			first = false;
		}
		else
		{
			is_pipe = line.find('|');
			if (is_pipe != std::string::npos)
			{
				key = line.substr(0, is_pipe);
				value = std::stod(line.substr(is_pipe + 1));
				_input.emplace_back(key, value);
			}
			else
				_input.emplace_back(line, 0);
		}
	}
	// for (const auto& n : _input)
	// 	std::cout << n.first << "=> " << n.second << std::endl;
	return 1;
}

void BitcoinExchange::process_data(std::ifstream& data)
{
	std::string		line;
	double			value;
	std::string		key;
	size_t			is_comma;
	bool first = true;

	while (std::getline(data, line))
	{
		if (first)
			first = false;
		else
		{
			is_comma = line.find(',');
			if (is_comma != std::string::npos)
			{
				key = line.substr(0, is_comma);
				value = std::stod(line.substr(is_comma + 1));
				_data.emplace_back(key, value);
			}
			else
				;
		}
	}
	for (const auto& b : _data)
		std::cout << b.first << "=> " << b.second << std::endl;
}

int check_input(std::string date, double value)
{
	std::regex	date_pattern(R"(^\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01])$)");

	if (std::regex::match(date, date_pattern))
		return 1;
	if (value < 0)
		return 2;
	if (value > 1000)
		return 3;
	return 0;
}

void BitcoinExchange::print_output(BitcoinExchange& btc)
{
	for (const auto& n : _input)
	{
		switch (check_input(n.first, n.second))
		{
		case 0:
			std::cout << n.first << " => " << n.second << btc.calculate_btc(n.first, n.second) << std::endl
			break;	
		case 1:
			std::cout << "Error: bad input => " << n.first << std::endl;
			break;
		case 2:
			std::cout << "Error: not a positive number." << std::endl;
			break;
		case 3:
			std::cout << "Error: too large a number." << std::endl;
			break;
		default:
			break;
		}
	}
}

double BitcoinExchange::calculate_btc(std::string date, double value)
{

}