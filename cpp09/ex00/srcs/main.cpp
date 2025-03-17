/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:31:37 by hipham            #+#    #+#             */
/*   Updated: 2025/03/17 09:16:55 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include <fstream>

int main(int ac, char *av[])
{
    std::string line;
    
    if (ac != 2)
        return std::cerr << "Error: Invalid argument.\n./btc [input.txt]\n", 0;
    std::ifstream input(av[1]);
    if (!input)
        return std::cerr << "Error: could not open file\n", 1;
    while (std::getline(input, line))
        std::cout << line << std::endl;
    input.close();
    return 0;
}