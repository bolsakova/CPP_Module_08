#ifndef SPAN_TPP
#define SPAN_TPP

#include "Span.hpp"

/**
 * @brief Template implementation of addRange.
 * Iterate through (first, last) and add each element via addNumber().
 * This ensure consistent overflow checking for each added element.
 */
template <typename InputIt>
void Span::addRange(InputIt first, InputIt last) {
	for (InputIt it = first; it != last; ++it)
		addNumber(*it);
}

#endif
