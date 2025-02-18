/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:00:16 by hipham            #+#    #+#             */
/*   Updated: 2025/02/17 21:01:50 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm():
    _name("Default AForm"),
    _signed(false),
    _signGrade(50),
    _execGrade(100) {
    // std::cout << "Default AForm constructor" << std::endl;
}

AForm::AForm(std::string const name, bool signedAForm, size_t const signGrade, size_t const execGrade)
    : _name(name), _signGrade(signGrade), _execGrade(execGrade) {
    try {
        if (signGrade < 1 || execGrade < 1)
            throw GradeTooHighExeption();
        else if (signGrade > 150 || execGrade > 150)
            throw GradeTooLowExeption();
        else {
            _signed = signedAForm;
        }
        
    }
    catch (GradeTooHighExeption &e) {
        std::cout << _name << " cannot be instantiated. " << e.what() << std::endl;
    }
    catch (GradeTooLowExeption &e) {
        std::cout << _name << " cannot be instantiated! " << e.what() << std::endl;
    }
}

AForm::AForm(AForm const &src): 
    _name(src._name),
    _signed(src._signed),
    _signGrade(src._signGrade),
    _execGrade(src._execGrade) {
}

AForm &AForm::operator=(const AForm& src) {
    if (this != &src) {
        _signed = src._signed;
    }
    return(*this);
    
}

AForm::~AForm() {
}

std::string AForm::getName(void) const {
    return(_name);
}

bool AForm::getSigned(void) const {
    return(_signed);
}

size_t AForm::getSignGrade(void) const {
    return(_signGrade);
}

size_t AForm::getExecGrade(void) const {
    return(_execGrade);
}

const char* AForm::GradeTooHighExeption::what() const noexcept {
    return("Grade is too high");            
}

const char* AForm::GradeTooLowExeption::what() const noexcept{
    return("Grade is too low");            
}

const char* AForm::FormNotSignedExeption::what() const noexcept{
    return("Form is not signed");            
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowExeption();
    else
        _signed = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    size_t signGrade = form.getSignGrade();
    size_t execGrade = form.getExecGrade();
    
    if ((signGrade >= 1 && signGrade <= 150)
    && (execGrade >= 1 && execGrade <= 150)) {
        os << form.getName() 
        << " is " << (form.getSigned() == true ? "signed" : "not signed")
        << ", grade to sign " << signGrade
        << ", grade to execute " << execGrade;
    }
    return(os);
}
