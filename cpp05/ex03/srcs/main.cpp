/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 10:35:55 by hipham            #+#    #+#             */
/*   Updated: 2025/02/18 17:14:45 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

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

    for(int i = 0; i < 6; i++)
    {
        EmployeeA.decrementGrade();   
    }
    std::cout << YELLOW << EmployeeA << RESET << std::endl;
    std::cout << YELLOW << ManagerA << RESET << std::endl;

    std::cout << PURPLE << "\n===== Shrubbery Creation Form =====\n" << RESET; 
    ShrubberyCreationForm scfForm;
    std::cout << GREEN << scfForm << RESET << std::endl;
    ManagerA.signForm(&scfForm);
    EmployeeA.executeForm(scfForm);
    ManagerA.executeForm(scfForm);
    ShrubberyCreationForm scf("MASHMELLOW");
    std::cout << GREEN << scf << RESET << std::endl;
    EmployeeA.signForm(&scf);
    
    std::cout << PURPLE << "\n===== Robotomy Request Form =====\n" << RESET;
    RobotomyRequestForm rbf;
    std::cout << GREEN << rbf << RESET << std::endl;
    EmployeeA.signForm(&rbf);
    ManagerA.signForm(&rbf);
    std::cout << GREEN << rbf << RESET << std::endl;
    ManagerA.executeForm(rbf);
    EmployeeA.executeForm(rbf);
    
    std::cout << PURPLE << "\n===== Presidential Pardon Form =====\n" << RESET;
    PresidentialPardonForm ppf;
    std::cout << GREEN << ppf << RESET << std::endl;
    EmployeeA.signForm(&ppf);
    ManagerA.signForm(&ppf);
    std::cout << GREEN << ppf << RESET << std::endl;
    ManagerA.executeForm(ppf);
    
    std::cout << PURPLE << "\n===== Intern =====\n" << RESET;
    Intern randomIntern;
    AForm *rrf;    
    rrf = randomIntern.makeForm("robotomy request", "Bender");
    if (rrf)
        std::cout << GREEN << *rrf << RESET << std::endl;
    AForm *pf;
    pf = randomIntern.makeForm("presidential request", "sos");
    if(pf)
        std::cout << GREEN << *pf << RESET << std::endl;
    AForm *sf;
    sf = randomIntern.makeForm("shrubbery request", "home");
    if(sf)
        std::cout << GREEN << *sf << RESET << std::endl;
    delete(rrf);
    delete(pf);
    delete(sf);
    return (0);
}

