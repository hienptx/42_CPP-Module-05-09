/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:36:15 by hipham            #+#    #+#             */
/*   Updated: 2025/04/06 15:23:36 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
#define RPN_H

#include<stack>
#include<string>
#include<iostream>
#include<exception>
#include<iterator>
#include<algorithm>
#include<cmath>
#include<sstream>

class RPN
{
	private:
		std::stack<int> _stack;
		std::string _input;

	public:
		RPN();
		RPN(const RPN &cpy);
		RPN &operator=(const RPN &cpy);
		~RPN();
		
		void validate_input(const std::string &input);
		void calculate(char op);
		void parse_input(RPN &rpn);
};

#endif