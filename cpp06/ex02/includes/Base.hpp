/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:21:48 by hipham            #+#    #+#             */
/*   Updated: 2025/02/25 21:22:30 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "../includes/Serializer.hpp"

class Serializer;

class Base
{
    public:
        virtual ~Base();
};
    
Base* generate(void);
void identify(Base* p);
void identify(Base& p);
#endif