/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:42:38 by hipham            #+#    #+#             */
/*   Updated: 2025/02/17 21:14:29 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm():
AForm("ROBOTOMY", false, 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(std::string const name):
AForm(name, false, 72, 45) {        
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src):
AForm(src) {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src) {
    if(this != &src)
        _signed = src._signed;
    return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::createTarget(void) const {
    std::cout << "DRILLING...NOISE..." << std::endl;
    srand(time(0));
    if(rand() % 2 == 0)
        std::cout << _name << " has been robotomized successfully 50%\n";
    else
        std::cout << _name << " failed\n";
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > _execGrade)
        throw AForm::GradeTooLowExeption();
    if (!_signed)
        throw AForm::FormNotSignedExeption();
    createTarget();
}
