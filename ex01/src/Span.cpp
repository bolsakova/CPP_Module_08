#include "../inc/Span.hpp"
#include <algorithm>
#include <limits>
#include <stdexcept>

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

/**
 * @brief Adds one integer to the container
 * @param number Integer to store.
 * @throws std::overflow_error If the container already reached its capacity
 */
void Span::addNumber(int number) {
	if (_data.size() >= _maxSize)
		throw std::overflow_error("Span is full");
	_data.push_back(number);
}

/**
 * @brief Returns the shortest distance between any two stored numbers.
 * The function sorts a copy of the stored values and checks only 
 * adjacent elements, which is enough to find the minimal difference.
 * @return The shortest span.
 * @throws std::runtime_error If there are fewer than two stored numbers.
 */
unsigned int Span::shortestSpan() const {
	if (_data.size() < 2)
		throw std::runtime_error("Not enough elements to  compute span");
	
	std::vector<int> sorted(_data);
	std::sort(sorted.begin(), sorted.end());

	unsigned int shortest = std::numeric_limits<unsigned int>::max();
	for (std::vector<int>::size_type i = 1; i < sorted.size(); ++i) {
		unsigned int diff = static_cast<unsigned int>(sorted[i] - sorted[i-1]);
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

/**
 * @brief Returns the longest distance between any two stored numbers.
 * The longest span is the difference between the smallest and the
 * largest stored values.
 * @return The longest span.
 * @throws std::runtime_error If there are fewer than two stored numbers.
 */
unsigned int Span::longestSpan() const {
	if (_data.size() < 2)
		throw std::runtime_error("Not enough elements to  compute span");

	std::vector<int>::const_iterator minIt = std::min_element(_data.begin(), _data.end());
	std::vector<int>::const_iterator maxIt = std::max_element(_data.begin(), _data.end());
	
	return static_cast<unsigned int>(*maxIt - *minIt);
}

/**
 * @brief Number of stored ints.
 * @return Current amount of stored values.
 */
unsigned int Span::size() const {
	return static_cast<unsigned int>(_data.size());
}
