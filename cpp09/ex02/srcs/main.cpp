/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:31:37 by hipham            #+#    #+#             */
/*   Updated: 2025/04/07 16:59:57 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <chrono>
#include "../includes/PmergeMe.hpp"
#include "../includes/PmergeList.hpp"
#include "../includes/PmergeDeque.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        std::cerr << "Usage: ./PmergeMe /list of positive integers/" << std::endl;
        std::cerr << "Example: ./PmergeMe 3 4 2 7" << std::endl;
        return 1;
    }
    // PmergeList pmerge;
    PmergeDeque pmerge2;
    try 
    {
        
        // pmerge.printFunction("Before: ");
        // const auto start = std::chrono::high_resolution_clock::now();   
        // pmerge.FordJohnsonSort();
        // const auto finish = std::chrono::high_resolution_clock::now();   
        // const std::chrono::duration<double, std::micro> duration = finish - start;
        // pmerge2.FordJohnsonSort();
        // pmerge.printFunction("After: ");
        // std::cout << std::fixed << std::setprecision(5);
        // std::cout << "Time to process a range of " << pmerge.size() << " elements: " 
        //         << duration.count() << " us" << std::endl;
        // std::cout << "Time to process a range of " << pmerge.size() << " elements: " 
        //         << duration.count() << " us" << std::endl;
        pmerge2.parse_input(ac, av);
        pmerge2.printFunction("Before: ");
        pmerge2.FordJohnsonSort();
        pmerge2.printFunction("After: ");
    }
    catch (const std::exception  &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}