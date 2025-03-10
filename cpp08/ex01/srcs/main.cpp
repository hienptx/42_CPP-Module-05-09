/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:31:37 by hipham            #+#    #+#             */
/*   Updated: 2025/03/10 17:42:20 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <string>
#include <iostream>
#include <time.h>
#include <cstdlib>

int main(void)
{
    Span sp = Span(5);

    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(12); // exception should be thrown
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what();
    }
    std::cout << sp.getSpanSize() << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    std::vector<int> varr;
    std::srand(std::time(NULL));
    for (int i = 0; i < 100; i++)
    {
        varr.push_back(std::rand() % 10000 + 1);
    }
    Span bigspan(900);
    bigspan.addMoreNumbers(varr);
    std::cout << bigspan.getSpanSize() << std::endl;
    std::cout << bigspan.shortestSpan() << std::endl;
    std::cout << bigspan.longestSpan() << std::endl;
}