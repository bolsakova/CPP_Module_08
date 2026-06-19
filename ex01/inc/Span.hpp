#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>

/**
 * @brief Span stores a fixed number of integers and computes spans.
 */
class Span {
	private:
		std::vector<int> _data;
		unsigned int _maxSize;
	public:
		// Construct a Span with capacity N
		explicit Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		// add numbers from a range of iterators
		template <typename InputIt>
		void addRange(InputIt first, InputIt last);
		
		// add a single number
		void addNumber(int number);
		// smallest diff between any 2 numbers
		unsigned int shortestSpan() const;
		// largest diff between any 2 numbers
		unsigned int longestSpan() const;
		// count of stored numbers
		unsigned int size() const;
};

#include "Span.tpp"

#endif
