/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:35:57 by hipham            #+#    #+#             */
/*   Updated: 2025/03/27 17:00:44 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <vector>
#include <utility>
#include <regex>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>

class BitcoinExchange
{
	private:
		std::vector<std::pair <std::string, double>> _input;
		std::multimap<std::string, double> _data;
		
	public:
		BitcoinExchange();
		~BitcoinExchange();

		int parse_input(std::ifstream &input);
		void process_data(std::ifstream &data);
		void print_output(BitcoinExchange& btc);
		double calculate_btc(std::string date, double value);
};

#endif