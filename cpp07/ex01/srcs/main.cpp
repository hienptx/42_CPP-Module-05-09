/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:31:37 by hipham            #+#    #+#             */
/*   Updated: 2025/03/20 12:40:43 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Iter.hpp"
#include <string>

#define PURPLE "\033[95m"
#define RESET "\033[0m"

int main( void )
{
    const int int_arr[4] = {1, 2, 3, 4};
    const std::string str_arr[4] = {"Hello", "world!", "Let's", "code"};
    
    std::cout << PURPLE << "====Test int Type====\n" << RESET;
    Iter(int_arr, 2, print_element<int>);
    std::cout << PURPLE << "====Test string Type====\n" << RESET;
    Iter(str_arr, 3, print_element<std::string>);
    return 0;
}