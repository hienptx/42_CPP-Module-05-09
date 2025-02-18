/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:32:57 by hipham            #+#    #+#             */
/*   Updated: 2025/02/18 15:58:37 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
    AForm("SHURBBERY", false, 145, 137) {
    // std::cout << "Default ShrubberyCreationForm constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const name):
    AForm(name, false, 145, 137) {
    // std::cout << "ShrubberyCreationForm constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src):
AForm(src) {
    // std::cout << "Copy ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src) {
    if (this != &src)
        _signed = src._signed;
    return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    // std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

void ShrubberyCreationForm::createTarget() const {
    //create file <Target>_shrubbery 
    std::ofstream file("file_SHRUBBERY");
    
    if(file.is_open()) {
        file <<      "*                   -\n";
        file <<     "***                 ---\n";
        file <<    "*****               -----\n";
        file <<   "*******             -------\n";
        file <<  "*********           ---------\n";
        file << "***********         -----------\n";
        file <<"*************       -------------\n";
        file <<      "|                   |\n";
        file.close();            
        std::cout << "File_Shrubbery is created" << std::endl;
    }
    else
        std::cerr << RED << "Error: unable to create file" << RESET << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!this->_signed)
        throw FormNotSignedExeption();
    if (executor.getGrade() > this->getExecGrade())
        throw GradeTooLowExeption();

    createTarget();  // No need to pass "Shrubbery_Trees"
}