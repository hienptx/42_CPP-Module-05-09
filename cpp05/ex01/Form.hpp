/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:17:54 by hipham            #+#    #+#             */
/*   Updated: 2025/02/16 20:35:31 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

// #include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form {
    private:
        std::string const   _name;
        bool                _signed;    
        size_t const        _signGrade;
        size_t const        _execGrade;
    public:
        Form();
        Form(std::string const name, bool signedForm, size_t const signGrade,
            size_t const execGrade);
        Form(Form const &src);
        Form &operator=(Form const &src);
        ~Form();

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
         
        void beSigned(Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream& os, const Form& form);

#endif