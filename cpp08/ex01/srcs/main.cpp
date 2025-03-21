/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:31:37 by hipham            #+#    #+#             */
/*   Updated: 2025/03/21 12:05:46 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <string>
#include <iostream>
#include <time.h>
#include <cstdlib>

#define PURPLE "\033[95m"
#define RESET "\033[0m"
#define MAX 100

int main(void)
{
    std::cout << PURPLE << "====Test Span of 5 numbers\n" << RESET;
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
    std::cout << "Span size: " << sp.getSpanSize() << std::endl;
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    
    std::cout << PURPLE << "====Test Span of MAX numbers\n" << RESET;
    std::vector<int> varr;
    std::srand(std::time(NULL));
    for (int i = 0; i < MAX; i++)
    {
        varr.push_back(std::rand() % 100000 + 1);
    }
    std::cout << "Finished generated 20000 numbers" << std::endl;
    Span bigspan(MAX);
    bigspan.addMoreNumbers(varr);
    std::cout << "Span size: " << bigspan.getSpanSize() << std::endl;
    std::cout << "Shortest span: " << bigspan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << bigspan.longestSpan() << std::endl;
}