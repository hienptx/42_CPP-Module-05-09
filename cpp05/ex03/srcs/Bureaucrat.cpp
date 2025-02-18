/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:17:27 by hipham            #+#    #+#             */
/*   Updated: 2025/02/17 21:19:35 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

/*__________ORTHODOX CANONICAL__________*/

// Constructor
Bureaucrat::Bureaucrat():_name("Default Officer"), _grade(100) {
    // std::cout << "Default Bureaucrat constructor" << std::endl;
}

// Parameterized constructor
Bureaucrat::Bureaucrat(std::string name, size_t grade): _name(name){
    // std::cout << "Parameters constructor" << std::endl;
    try{
        if (grade < 1)
            throw GradeTooHighExeption();
        else if (grade > 150)
            throw GradeTooLowExeption();
        else 
           this->_grade = grade;
    }
    catch (GradeTooHighExeption &e) {
        std::cout  << _name << " cannot be instantiated! " << e.what() << std::endl;
    }
    catch (GradeTooLowExeption &e) {
        std::cout << _name << " cannot be instantiate! " << e.what() << std::endl;
    }
}

// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src._name), _grade(src._grade) {
    // std::cout << "Copy constructor" << std::endl;
}

// assigment operator overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat& src) {
    // std::cout << "= assignment operator" << std::endl;
    if (this != &src) {
        _grade = src._grade;
    }
    return(*this);
}

// Destructor
Bureaucrat::~Bureaucrat() {
    // std::cout << "Destructor" << std::endl;
}
/*_________________________________________*/

// Getters
std::string Bureaucrat::getName(void) const {
    return(_name);
}

size_t Bureaucrat::getGrade(void) const {
    return(_grade);
}

// exeption funtions
const char* Bureaucrat::GradeTooHighExeption::what() const noexcept {
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowExeption::what() const noexcept {
    return ("Grade is too low");
}

// do-st functions
void Bureaucrat::incrementGrade() {
    try {     
    if (_grade <= 1)
        throw GradeTooHighExeption();
    _grade -= 1;
    }
    catch (GradeTooHighExeption &e) {
        std::cout << _name << " cannot increment grade! " << e.what() << std::endl;
    }
}

void Bureaucrat::decrementGrade() {
    try {
        if (_grade >= 150)
            throw GradeTooLowExeption();
        _grade += 1;
    }
    catch (GradeTooLowExeption &e) {
        std::cout << _name << " cannot decrement grade! " << e.what() << std::endl;
    }        
}

void Bureaucrat::signForm(AForm *form) {
    try {
        form->beSigned(*this);
        std::cout << this->getName() << " signed " << form->getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << "Error: " << RESET;
        std::cout << this->getName() << " couldn’t sign " << form->getName() << " because: " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) {
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch (AForm::FormNotSignedExeption& e) {
        std::cerr << RED << "Execution Error: " << RESET << e.what() << std::endl;
    }
    catch (AForm::GradeTooLowExeption& e) {
        std::cout << RED << "Error: " << RESET; 
        std::cout << _name << " couldn't execute ";
        std::cout << form.getName() << " because: "; 
        std::cout << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << RED << "Unknown Error: " << RESET << e.what() << std::endl;
    }
}

// print << operator for bureaucrat
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() >= 1 && bureaucrat.getGrade() <= 150)
        os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
