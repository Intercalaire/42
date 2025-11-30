/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:17:16 by vgodart           #+#    #+#             */
/*   Updated: 2025/03/19 23:17:19 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>

class Span {
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();


		void addNumber(int value);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		template<typename T>
			void addRange(T first, T last);

	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;
};

#endif