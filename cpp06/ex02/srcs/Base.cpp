/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:21:24 by hipham            #+#    #+#             */
/*   Updated: 2025/03/19 17:51:48 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base::~Base(){
}

Base *generate(void) {
    std::srand(std::time(0));
    int random = rand() % 3;

    switch (random)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return nullptr;
    }
}

void identify(Base* p) {
    if(dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
    }

void identify(Base& p) {
    try {
        (void) dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch(const std::bad_cast& e){
    }
    try {
        (void) dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    }
    catch(const std::bad_cast& e) {
    }
    try {
        (void) dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    }
    catch(const std::bad_cast& e) {
    }
}