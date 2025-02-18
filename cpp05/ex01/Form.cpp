/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:00:16 by hipham            #+#    #+#             */
/*   Updated: 2025/02/17 17:28:56 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form():
    _name("Default Form"),
    _signed(false),
    _signGrade(50),
    _execGrade(100) {
    // std::cout << "Default Form constructor" << std::endl;
}

Form::Form(std::string const name, bool signedForm, size_t const signGrade, size_t const execGrade)
    : _name(name), _signGrade(signGrade), _execGrade(execGrade) {
    try {
        if (signGrade < 1 || execGrade < 1)
            throw GradeTooHighExeption();
        else if (signGrade > 150 || execGrade > 150)
            throw GradeTooLowExeption();
        else {
            _signed = signedForm;
        }
        
    }
    catch (GradeTooHighExeption &e) {
        std::cout << _name << " cannot be instantiated. " << e.what() << std::endl;
    }
    catch (GradeTooLowExeption &e) {
        std::cout << _name << " cannot be instantiated! " << e.what() << std::endl;
    }
}

Form::Form(Form const &src): 
    _name(src._name),
    _signed(src._signed),
    _signGrade(src._signGrade),
    _execGrade(src._execGrade) {
}

Form &Form::operator=(const Form& src) {
    if (this != &src) {
        _signed = src._signed;
    }
    return(*this);
    
}

Form::~Form() {
}

std::string Form::getName(void) const {
    return(_name);
}

bool Form::getSigned(void) const {
    return(_signed);
}

size_t Form::getSignGrade(void) const {
    return(_signGrade);
}

size_t Form::getExecGrade(void) const {
    return(_execGrade);
}

const char* Form::GradeTooHighExeption::what() const noexcept {
    return("Grade is too high");            
}

const char* Form::GradeTooLowExeption::what() const noexcept{
    return("Grade is too low");            
}
 
void Form::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowExeption();
    else
        _signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
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
