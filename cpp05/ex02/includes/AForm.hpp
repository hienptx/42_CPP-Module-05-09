/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:17:54 by hipham            #+#    #+#             */
/*   Updated: 2025/02/17 21:01:12 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

// #include "Bureaucrat.hpp"
#include <iostream>

#define PURPLE "\033[95m"
#define GREEN  "\033[92m"
#define RED    "\033[91m"
#define YELLOW "\033[93m"
#define BLUE   "\033[94m"
#define RESET  "\033[0m"

class Bureaucrat;

class AForm {
    protected:
        std::string const   _name;
        bool                _signed;    
        size_t const        _signGrade;
        size_t const        _execGrade;
    public:
        AForm();
        AForm(std::string const name, bool signedAForm, size_t const signGrade,
            size_t const execGrade);
        AForm(AForm const &src);
        AForm &operator=(AForm const &src);
        ~AForm();
        
        std::string getName(void) const;
        bool getSigned(void) const;
        size_t getSignGrade(void) const;
        size_t getExecGrade(void) const;

        class GradeTooHighExeption: public std::exception {
            public:
                const char* what() const noexcept override;
        }; 
        class GradeTooLowExeption: public std::exception {
            public:
                const char* what() const noexcept override;
        };
        class FormNotSignedExeption: public std::exception {
            public:
                const char* what() const noexcept override;
        };
         
        void beSigned(Bureaucrat &bureaucrat);  // pure virtual function
        virtual void execute(Bureaucrat const &executor) const = 0;
    };
    
std::ostream &operator<<(std::ostream& os, const AForm& form);

#endif