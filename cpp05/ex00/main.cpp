/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 10:35:55 by hipham            #+#    #+#             */
/*   Updated: 2025/03/17 15:32:13 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
        Bureaucrat defaultB; //by default, bureaucrat name: "Officer"; grade: 100
        std::cout << defaultB << std::endl;
    
        Bureaucrat ManagerA("Manager A", 2);
        std::cout << ManagerA << std::endl;
    
        Bureaucrat ManagerB("Manager B", 0);
        std::cout << ManagerB;
    
        Bureaucrat EmployeeA("Employee A", 145);
        std::cout << EmployeeA << std::endl;
    
        Bureaucrat EmployeeB("Employee B", 155);
        std::cout << EmployeeB;

        ManagerA.incrementGrade();
        std::cout << ManagerA << std::endl;
        ManagerA.incrementGrade();
        
        for(int i = 0; i < 7; i++)
        {
            EmployeeA.decrementGrade();   
        }
            
        std::cout << ManagerA << std::endl;
        std::cout << EmployeeA << std::endl;
    return (0);
}
