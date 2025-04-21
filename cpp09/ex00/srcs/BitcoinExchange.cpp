/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:39:02 by hipham            #+#    #+#             */
/*   Updated: 2025/04/21 22:04:29 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

/*==========OCCF==========*/

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
	_input = cpy._input;
	_data = cpy._data;
}

BitcoinExchange::~BitcoinExchange() {}

/*==========OVERLOADING OPERATORS==========*/

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_input = other._input;
		_data = other._data;
	}
	return *this;
}

/*==========MEMBER FUNCTIONS==========*/

int BitcoinExchange::parse_input(std::ifstream &input)
{
	std::string		line;
	size_t			is_pipe;
	std::string		key;
	std::string		val;
	double			value;
	bool			first = true;
	std::regex 		first_line(R"(^date \| value$)");
	std::regex		string(R"(^[?0-9]+\.[?0-9]+$)");
	
	while(std::getline(input, line))
	{
		if (first)
		{
			if(std::regex_match(line, first_line) == false)
				return std::cerr << "Error: Invalid input\n", 0;
			first = false;
		}
		else
		{
			is_pipe = line.find('|');
			if (is_pipe != std::string::npos && std::count(line.begin(), line.end(), '|') == 1)
			{
				key = line.substr(0, is_pipe);
				std::string l2 = line.substr(is_pipe + 2);
				if (key == "" || l2 == "" || std::regex_match(l2, string) == false)
					_input.emplace_back("Wrong format", 0);
				else
				{
					try
					{
						value = std::stod(line.substr(is_pipe + 1));
					}
					catch(const std::exception& e)
					{
						_input.emplace_back(line.substr(is_pipe + 1), 0);
					}
					_input.emplace_back(key, value);
				}
			}
			else
				_input.emplace_back("Wrong format", 0);
		}
	}
	return 1;
}

void BitcoinExchange::process_data(std::ifstream& data)
{
	std::string		line;
	double			value;
	std::string		key;
	size_t			is_comma;
	bool first = true;
	std::regex fist_line(R"(^date\s*,\s*exchange_rate$)");

	while (std::getline(data, line))
	{
		if (first)
		{
			first = false;
			if (!(std::regex_match(line, fist_line)))
			{
				std::cerr << "Error: Invalid Data Set\n";
				exit(0);
			}
		}
		else
		{
			is_comma = line.find(',');
			if (is_comma != std::string::npos)
			{
				key = line.substr(0, is_comma);
				try
				{
					value = std::stod(line.substr(is_comma + 1));
				}
				catch(const std::exception& e)
				{
					continue ;
				}
				_data.emplace(key, value);
			}
			else
			{
				continue ;
			}
		}
	}
}

bool is_valid_date(const std::string& date)
{
	int year, month, day;
	char dash1, dash2;

	std::istringstream date_stream(date);
	if (!(date_stream >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-')
		return false;
	if (month < 1 || month > 12)
		return false;
	int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	// Adjust for leap year
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		days_in_month[1] = 29;
	if (day < 1 || day > days_in_month[month - 1])
		return false;

	return true;
}

int check_input(std::string date, double value)
{
	if (!is_valid_date(date))
		return 1;
	else if (value < 0)
		return 2;
	else if (value > 1000)
		return 3;
	else
		return 0;
}

void BitcoinExchange::print_output(BitcoinExchange& btc)
{
	for (const auto& n : _input)
	{
		switch (check_input(n.first, n.second))
		{
		case 0:
			if (btc.calculate_btc(n.first, n.second) == -1)
				std::cout << "Error: no data found for date => " << n.first << std::endl;
			else
			{
				std::cout << n.first << "=> " << n.second << " = ";
				std::cout << btc.calculate_btc(n.first, n.second) << std::endl;
			}
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
	auto exact = _data.find(date);
	if (exact != _data.end())
	{
		return(value * exact->second);
	}
	else
	{
		auto it = _data.lower_bound(date);
		if (it == _data.begin())
			return -1;
		else
		{
			--it;
			return(value * (it->second));
		}
	}
	return -1;
}