/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:01:05 by hipham            #+#    #+#             */
/*   Updated: 2025/02/18 16:53:49 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern(){
}

Intern::Intern(Intern const &src) {
    (void)src;
}

Intern &Intern::operator=(Intern const &src) {
    (void)src;
    return(*this);
}

Intern::~Intern() {
}

int getFormID(std::string const &name) {
    if(name == "shrubbery request") return 1;
    if(name == "robotomy request") return 2;
    if(name == "presidential request") return 3;
    return -1;
}

AForm *Intern::makeForm(std::string const name, std::string const target) {
    switch (getFormID(name))
    {
        case 1:
            std::cout << "Intern creates " << target << std::endl;
            return new ShrubberyCreationForm(target);
        case 2:
            std::cout << "Intern creates " << target << std::endl;
            return new RobotomyRequestForm(target);
        case 3:
            std::cout << "Intern creates " << target << std::endl;
            return new PresidentialPardonForm(target);        
        default:
            std::cout << "Invalid form's name\nAcceptable:\n";
            std::cout << "presidential request\n";
            std::cout << "robotomy request\n";
            std::cout << "shrubbery request\n";
            return nullptr;
    }
}
