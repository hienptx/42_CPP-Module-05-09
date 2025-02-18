/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:19:58 by hipham            #+#    #+#             */
/*   Updated: 2025/02/18 15:32:46 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string const name);
        PresidentialPardonForm(PresidentialPardonForm const &src);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &src);
        virtual ~PresidentialPardonForm();

        void createTarget(void) const;
        void execute(Bureaucrat const &executor) const override;
};

#endif