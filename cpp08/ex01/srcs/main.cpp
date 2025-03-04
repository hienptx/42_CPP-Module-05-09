/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:31:37 by hipham            #+#    #+#             */
/*   Updated: 2025/03/03 13:56:25 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Iter.hpp"
#include <string>

int main( void )
{
    const int int_arr[4] = {1, 2, 3, 4};
    print_element(int_arr[0]);
    const std::string str_arr[4] = {"a", "b", "c", "d"};
    
    Iter(int_arr, 4, print_element<int>);
    Iter(str_arr, 4, print_element<std::string>);
    return 0;
}