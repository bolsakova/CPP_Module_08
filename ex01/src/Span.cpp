#include "../inc/Span.hpp"
#include <algorithm>
#include <limits>

/**
 * @brief Constructs a Span with a fixed capacity
 * @param n Max number of ints that can be stored in the object.
 */
Span::Span(unsigned int n) : _data(), _maxSize(n) {}

Span::Span(const Span& other) : _data(other._data), _maxSize(other._maxSize) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_data = other._data;
		_maxSize = other._maxSize;
	}
	return *this;
}

Span::~Span() {}

// add a single number
void Span::addNumber(int number) {}

// smallest diff between any 2 numbers
unsigned int Span::shortestSpan() const {}

// largest diff between any 2 numbers
unsigned int Span::longestSpan() const {}

// count of stored numbers
unsigned int Span::size() const {}
