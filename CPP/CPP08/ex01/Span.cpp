/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:17:16 by vgodart           #+#    #+#             */
/*   Updated: 2025/03/19 23:17:19 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) {
	*this = other;
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int value) {
	if (_numbers.size() >= _maxSize) {
		throw std::out_of_range("Span is full");
	}
	_numbers.push_back(value);
}

unsigned int Span::shortestSpan() const {
	if (_numbers.size() < 2) {
		throw std::logic_error("Not enough numbers to find a span");
	}

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	unsigned int minSpan = std::numeric_limits<unsigned int>::max();
	for (size_t i = 0; i < sorted.size() - 1; ++i) {
		unsigned int diff = sorted[i + 1] - sorted[i];
		if (diff < minSpan) {
			minSpan = diff;
		}
	}

	return minSpan;
}

unsigned int Span::longestSpan() const {
	if (_numbers.size() < 2) {
		throw std::logic_error("Not enough numbers to find a span");
	}

	int minVal = *std::min_element(_numbers.begin(), _numbers.end());
	int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

	return maxVal - minVal;
}

// Template implementation moved here from header
template<typename T>
void Span::addRange(T first, T last) {
    size_t count = std::distance(first, last);

    if (_numbers.size() + count > _maxSize) {
        throw std::out_of_range("Not enough space in Span");
    }

    _numbers.insert(_numbers.end(), first, last);
}

// Explicit template instantiations for common iterator types
template void Span::addRange<std::vector<int>::iterator>(std::vector<int>::iterator, std::vector<int>::iterator);
template void Span::addRange<std::vector<int>::const_iterator>(std::vector<int>::const_iterator, std::vector<int>::const_iterator);
