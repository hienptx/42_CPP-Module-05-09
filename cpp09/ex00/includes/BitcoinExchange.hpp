/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:35:57 by hipham            #+#    #+#             */
/*   Updated: 2025/03/20 17:50:38 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <deque>
#include <regex>

template <class T>
class BitcoinExchange
{
	private:
		size_t		_n;
		// std::deque _date;
		// std::deque _valuePerBtc;
		// std::deque _totalValue;
	public:	
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void setDate(std::string date);
		// void setValuePerBtc(int valuePerBtc);
		// void setTotalValue(double totalValue);
};

BitcoinExchange::BitcoinExchange(size_t n): n {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	_date = other._date;
	_valuePerBtc = other._valuePerBtc;
	_totalValue = other._totalValue;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_date = other._date;
		_valuePerBtc = other._valuePerBtc;
		_totalValue = other._totalValue;
	}
	return(*this);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::setDate(std::string date)
{
	
}
