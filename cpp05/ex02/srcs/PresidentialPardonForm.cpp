/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:22:12 by hipham            #+#    #+#             */
/*   Updated: 2025/02/17 21:24:58 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
AForm("PRESIDENTIAL", false, 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(std::string const name):
AForm(name, false, 25, 5) {
}   

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src):
AForm(src) {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src) {
    if(this != &src)
        _signed = src._signed;
    return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void PresidentialPardonForm::createTarget(void) const {
    std::cout << _name << " has been pardoned by Zafod Beeblebrox\n";
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > _execGrade)
        throw AForm::GradeTooLowExeption();
    if (!_signed)
        throw AForm::FormNotSignedExeption();
    createTarget();
}
