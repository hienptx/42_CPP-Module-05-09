/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:36:15 by hipham            #+#    #+#             */
/*   Updated: 2025/03/10 17:42:42 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#include<vector>
#include<iterator>
#include<algorithm>
#include<cmath>

class Span
{
	private:
		unsigned int	N; // Number if integers
		std::vector<int> span;

	public:
		// Span();
		Span(unsigned int n);
		Span(Span const &copy);
		Span &operator=(Span const &copy);
		~Span();

		unsigned int getSpanSize();
		void addNumber(int num); //add single number to span
		void addMoreNumbers(std::vector<int>& arr);
		unsigned int shortestSpan();
		unsigned int longestSpan();
};

#endif