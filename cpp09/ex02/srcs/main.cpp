/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:31:37 by hipham            #+#    #+#             */
/*   Updated: 2025/04/21 16:48:03 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <chrono>
#include "../includes/PmergeMe.hpp"
#include "../includes/PmergeVector.hpp"
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
    PmergeVector pmerge1;
    PmergeDeque pmerge2;
    try 
    {
        std::cout << std::fixed << std::setprecision(5);
        pmerge1.parse_input(ac, av);
        pmerge2.parse_input(ac, av);
        
        // pmerge1.printFunction(pmerge1.getVector(), "Before: ");
        const auto start1 = std::chrono::high_resolution_clock::now();   
        pmerge1.FordJohnsonSort();
        const auto finish1 = std::chrono::high_resolution_clock::now();   
        const std::chrono::duration<double, std::micro> duration1 = finish1 - start1;
        // pmerge1.printFunction(pmerge1.getVector(), "After: ");
        
        pmerge2.printFunction(pmerge2.getDeque(), "Before:  ");
        const auto start = std::chrono::high_resolution_clock::now();   
        pmerge2.FordJohnsonSort();
        const auto finish = std::chrono::high_resolution_clock::now();   
        const std::chrono::duration<double, std::micro> duration = finish - start;
        pmerge2.printFunction(pmerge2.getDeque(), "After:   ");

        std::cout << "Time to process a range of " << pmerge2.getSize(pmerge2.getDeque()) << " elements with std::deque: " 
            << duration.count() << " us" << std::endl;
        std::cout << "Time to process a range of " << pmerge1.getSize(pmerge1.getVector()) << " elements with std::vector: " 
            << duration1.count() << " us" << std::endl;
        std::cout << "Number of comparisons from FJAlgr: " << pmerge2.F(pmerge2.getSize(pmerge2.getDeque())) << std::endl;
        std::cout << "Number of comparisons: " << pmerge2.getCounter() << std::endl;
    }
    catch (const std::exception  &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}