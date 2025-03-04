/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:31:37 by hipham            #+#    #+#             */
/*   Updated: 2025/03/04 17:12:13 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Easyfind.hpp"
#include <iostream>
#include <vector>

int main( void )
{
    std::vector<int> numbers = {2, 6, 0, 2};
    try {
        std::vector<int>::iterator it;
        
        it = easyfind(numbers, 6);
        for(; it != numbers.end(); ++it)
            std::cout << *it << " ";
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n";
    return 0;
}