/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:42:55 by hipham            #+#    #+#             */
/*   Updated: 2025/02/17 20:41:21 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm: public AForm {
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const name);
        RobotomyRequestForm(RobotomyRequestForm const &src);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &src);
        ~RobotomyRequestForm();

        void createTarget(void) const;
        void execute(Bureaucrat const &executor) const override;
};

#endif
