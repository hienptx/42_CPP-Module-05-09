/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:31:37 by hipham            #+#    #+#             */
/*   Updated: 2025/03/20 13:47:31 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Array.hpp"

#define PURPLE "\033[95m"
#define RESET "\033[0m"

int main()
{
    Array<int> numbers(MAX_VAL);

    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
    }
    std::cout << "Size of numbers array: " << numbers.size() << std::endl;
    //SCOPE
    Array<int> tmp = numbers;
    std::cout << PURPLE << "Printing Coppied array\n" << RESET; 
    for(int i = 0; i < tmp.size(); i++)
        std::cout << tmp[i] << std::endl;
    Array<int> test(tmp);
    // Access invalid address
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[4] = 9;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << PURPLE << "After change value idx [4] in original array\n" << RESET; 
    for(int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << std::endl;
    std::cout << PURPLE << "Printing Coppied array\n" << RESET;
    for(int i = 0; i < tmp.size(); i++)
        std::cout << tmp[i] << std::endl;

    return 0;
}