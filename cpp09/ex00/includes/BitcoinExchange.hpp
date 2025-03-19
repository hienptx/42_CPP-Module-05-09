/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:35:57 by hipham            #+#    #+#             */
/*   Updated: 2025/03/19 19:14:16 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <deque>
#include <regex>

class BitcoinExchange
{
	private:
		std::deque date;
		std::deque valuePerBtc;
		std::deque totalValue;
	public:	
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();
};

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
: date = other.date,
valuePerBtc = other.valuePerBtc,
totalValue = other.totalValue
{}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	
}


