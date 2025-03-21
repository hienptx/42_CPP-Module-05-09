/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:31:37 by hipham            #+#    #+#             */
/*   Updated: 2025/03/21 11:44:35 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Easyfind.hpp"
#include <iostream>
#include <vector>

#define PURPLE "\033[95m"
#define RESET "\033[0m"

int main( void )
{
    std::vector<int> numbers = {2, 6, 0, 2};
    try {
        std::vector<int>::iterator it, it1, it2;
        
        std::cout << PURPLE << "Find 6 in arr [2,6,0,2]\n" << RESET;
        it = easyfind(numbers, 6);
        for(; it != numbers.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;

        std::cout << PURPLE << "Find 2 in arr [2,6,0,2]\n" << RESET;
        it1 = easyfind(numbers, 2);
        for(; it1 != numbers.end(); ++it1)
            std::cout << *it1 << " ";
        std::cout << std::endl;
        
        std::cout << PURPLE << "Find 9 in arr [2,6,0,2]\n" << RESET;
        it2 = easyfind(numbers, 9);
        for(; it2 != numbers.end(); ++it2)
            std::cout << *it2 << " ";
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what();
    }
    std::cout << "\n";
    return 0;
}