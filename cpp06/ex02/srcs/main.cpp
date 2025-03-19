/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:51:10 by hipham            #+#    #+#             */
/*   Updated: 2025/03/19 17:41:00 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

int main()
{
    Base *ptr = generate();
    
    std::cout << "Identify &ptr\n";
    identify(ptr);
    std::cout << "Identify *ptr\n";
    identify(*ptr);
    delete ptr;
    return 0;
}
