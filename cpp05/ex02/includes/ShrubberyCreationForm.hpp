/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:19:42 by hipham            #+#    #+#             */
/*   Updated: 2025/02/17 21:06:42 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm {
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const name);
        ShrubberyCreationForm(ShrubberyCreationForm const &src);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);
        ~ShrubberyCreationForm();
        
        void createTarget() const;
        void execute(Bureaucrat const &executor) const override;
};

#endif
