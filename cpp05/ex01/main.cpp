/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 10:35:55 by hipham            #+#    #+#             */
/*   Updated: 2025/03/17 15:40:48 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

#define PURPLE "\033[95m"
#define GREEN  "\033[92m"
#define RED    "\033[91m"
#define YELLOW "\033[93m"
#define BLUE   "\033[94m"
#define RESET  "\033[0m"

int main()
{
    std::cout << PURPLE << "\n===== Bureaucrats Creation =====\n" << RESET;
    Bureaucrat defaultB; // by default, bureaucrat name: "Officer"; grade: 100
    std::cout << GREEN << defaultB << RESET << std::endl;

    Bureaucrat ManagerA("Manager A", 2);
    std::cout << GREEN << ManagerA << RESET << std::endl;

    Bureaucrat ManagerB("Manager B", 0);
    std::cout << RED << ManagerB << RESET; // Invalid

    Bureaucrat EmployeeA("Employee A", 145);
    std::cout << GREEN << EmployeeA << RESET << std::endl;

    Bureaucrat EmployeeB("Employee B", 155);
    std::cout << RED << EmployeeB << RESET; // Invalid

    std::cout << PURPLE << "\n===== Grade Modifications =====\n" << RESET;
    ManagerA.incrementGrade();
    std::cout << YELLOW << ManagerA << RESET << std::endl;

    try {
        ManagerA.incrementGrade();
    } catch (const std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW << EmployeeA << RESET << std::endl;
    for(int i = 0; i < 6; i++)
    {
        EmployeeA.decrementGrade();
    }

    std::cout << PURPLE << "\n===== Form Creation =====\n" << RESET;
    Form DefaulForm;
    
    Form formA("Form A", false, 0, 0);
    std::cout << BLUE << formA << RESET;

    Form formB("Form B", false, 60, 100);
    std::cout << BLUE << formB << RESET << std::endl;

    std::cout << PURPLE << "\n===== Signing Forms =====\n" << RESET;
    ManagerA.signForm(&formB);
    std::cout << GREEN << formB << RESET << std::endl;

    EmployeeA.signForm(&formB);
    
    return (0);
}

