/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:31:37 by hipham            #+#    #+#             */
/*   Updated: 2025/04/07 16:01:55 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int main(int ac, char **av)
{
    if (ac > 2)
    {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        std::cerr << "Usage: ./rpn \"expression\"" << std::endl;
        std::cerr << "Example: ./rpn \"3 4 + 2 * 7 /\"" << std::endl;
        return 1;
    }
    RPN rpn;
    try 
    {
        rpn.validate_input(av[1]);
        rpn.parse_input(rpn);
    }
    catch (const std::exception  &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
