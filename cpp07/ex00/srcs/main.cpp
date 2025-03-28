/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:31:37 by hipham            #+#    #+#             */
/*   Updated: 2025/03/20 12:25:53 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Whatever.hpp"
#include <iostream>

#define PURPLE "\33[95m"
#define RESET "\033[0m"

int main( void )
{
    int a=2;
    int b=3;
    
    std::cout << PURPLE << "====TEST int TYPE====\n" << RESET;
    std::cout << "Before swap: ";
    std::cout << "a = " << a << ", b = " << b  << std::endl;
    ::Swap(a,b);
    std::cout << "After swap: ";
    std::cout << "a = " << a << ", b = " << b  << std::endl;
    std::cout << "min( a, b ) = " << ::Min(a,b) << std::endl;
    std::cout << "max( a, b ) = " << ::Max(a,b) << std::endl;
    
    std::cout << PURPLE << "====TEST string TYPE====\n" << RESET;
    std::string c ="chaine1";
    std::string d ="chaine2";
    
    std::cout << "Before swap: ";
    std::cout <<"c = "<< c <<", d = "<< d << std::endl;
    ::Swap(c,d);
    std::cout << "After swap: ";
    std::cout <<"c = "<< c <<", d = "<< d << std::endl;
    std::cout << "min( c, d ) = " << ::Min(c,d) << std::endl;
    std::cout << "max( c, d ) = " << ::Max(c,d) << std::endl;
    
    
    return 0;
}