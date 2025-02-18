/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 10:36:08 by hipham            #+#    #+#             */
/*   Updated: 2025/02/16 15:06:09 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
    private:
        std::string const _name;
        size_t      _grade;
    public:
        //Othodox canonical form
        Bureaucrat();
        Bureaucrat(std::string const name, size_t grade);
        Bureaucrat(Bureaucrat const &src);
        Bureaucrat &operator=(Bureaucrat const &src);
        ~Bureaucrat();
        
        // Getter functions
        std::string getName(void) const;
        size_t getGrade(void) const;
        
        // exeption customized message
        class GradeTooHighExeption: public std::exception {
            public:
                const char* what() const noexcept override;
        };
        class GradeTooLowExeption: public std::exception {
            public:
                const char* what() const noexcept override;
        };
        
        // Do-something functions
        void incrementGrade();
        void decrementGrade();
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
#endif
