/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:31:37 by hipham            #+#    #+#             */
/*   Updated: 2025/03/26 18:22:31 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

/*
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
*/

int main(int ac, char *av[])
{
    BitcoinExchange btc;

    if (ac != 2)
        return std::cerr << "Error: Invalid argument.\n./btc [input.txt]\n", 0;

    std::ifstream input(av[1]);
    if (!input)
        return std::cerr << "Error: could not open file\n", 1;
    if (!btc.parse_input(input))
        return input.close(), 0;
    std::ifstream data("data.csv");
    if (!data)
        return std::cerr << "Error: could not open file\n", 1;
    btc.process_data(data);
    btc.print_output(btc);
    input.close();
    data.close();
    return 0;
}
