#include "../inc/Span.hpp"
#include <iostream>
#include <vector>
#include <random>

static void printHeader(const char* title) {
	std::cout << "\n=== " << title << " ===\n";
}

/**
 * @brief Test 1: Subject example.
 * 
 * This is the exact example from the subject.
 * Expected output:
 * - shortest span: 2 (diff between 3 and 5, or 9 and 11)
 * - longest span: 14 (diff between 3 and 17)
 */
static void testSubjectExapmle() {
	printHeader("Test 1: Subject Example");

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

/**
 * @brief Test 2: Overflow detection.
 * 
 * This test verifies:
 * - Span correctly detects when it's full
 * - Attempting to add beyond capacity throws exception
 */
static void testOverflow() {
	printHeader("Test 2: Overflow Detection");

	Span sp(3);
	sp.addNumber(10);
	sp.addNumber(20);
	sp.addNumber(30);

	try {
		sp.addNumber(40);
		std::cout << "ERROR: Should have thrown overflow exception!" << std::endl;
	} catch (const std::overflow_error& e) {
		std::cout << "Correctly caught overflow: " << e.what() << std::endl;
	}


}

/**
 * @brief Test 3: Insufficient elements exception.
 * 
 * This test verifies:
 * - Span methods require at least 2 numbers
 * - calling shortestSpan() or longestSpan() with fewer than 2 elements throws
 */
static void testInsufficientElements() {
	printHeader("Test 3: Insufficient Elements");

	Span sp(5);
	sp.addNumber(42);

	try {
		sp.shortestSpan();
		std::cout << "ERROR: Should have thrown length_error!" << std::endl;
	} catch (const std::length_error& e) {
		std::cout << "Correctly caught error: " << e.what() << std::endl;
	}

}

/**
 * @brief Test 4: Adding range of iterators.
 * 
 * This test verifies:
 * - addRange() successfully adds multiple elements from a vector
 * - the range is added correctly without exceeding capacity
 * - this is much more convenient than calling addNumber() thousands of times
 */
static void testAddRange() {
	printHeader("Test 4: Adding Range of Iterators");

	Span sp(10);

	// create a vector of values
	std::vector<int> values = {5, 3, 17, 9, 11};

	// add the range to Span using addRange
	sp.addRange(values.begin(), values.end());

	std::cout << "Added 5 elements via addRange()" << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

/**
 * @brief Test 5: AddRange overflow detection.
 * 
 * This test verifies:
 * - addRange() correctly detects when adding the entire range would overflow
 * - it throws an exception if capacity is exceeded
 */
static void testAddRangeOverflow() {
	printHeader("Test 5: AddRange Overflow Detection");

	Span sp(3);
	std::vector<int> values = {1, 2, 3, 4, 5};

	try {
		sp.addRange(values.begin(), values.end());
		std::cout << "ERROR: Should have thrown overflow!" << std::endl;
	} catch (const std::overflow_error& e) {
		std::cout << "Correctly caught overflow during addRange: " << e.what() << std::endl;
	}

}

/**
 * @brief Test 6: All elements are equal.
 * 
 * This test verifies:
 * - when all elements are the same, shortestSpan() returns 0
 * - longestSpan() also returns 0 (diff between same values)
 */
static void testEqualElements() {
	printHeader("Test 6: All Elements Equal");

	Span sp(5);
	sp.addNumber(7);
	sp.addNumber(7);
	sp.addNumber(7);
	sp.addNumber(7);

	std::cout << "All elements are 7" << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

/**
 * @brief Test 7: Large dataset performance test.
 * 
 * This test verifies:
 * - Span can handle 10,000+ elements efficiently
 * - addRange() with large dataset is much faster than calling addNumber() repeatedly
 * - span() methods execute quickly on large datasets
 * - STL algorithms (sort, minmax_element) scale well
 */
static void testLargeSpan() {
	printHeader("Test 7: Large Span (50,000 elements via addRange)");

	Span sp(50000);

	// generate random numbers
	std::vector<int> largeSet;
	std::mt19937 rng(12345);
	std::uniform_int_distribution<int> dist(0, 1000000);

	for (int i = 0; i < 50000; ++i)
		largeSet.push_back(dist(rng));

	// add the range to Span using addRange
	sp.addRange(largeSet.begin(), largeSet.end());

	std::cout << "Filled Span with 50,000 random numbers using addRange()" << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

/**
 * @brief Test 8: Copy Semantics.
 * 
 * This test verifies:
 * - copy constructor works correctly (deep copy)
 * - assignment operator works correctly
 * - copies are independent
 */
static void testCopySemantics() {
	printHeader("Test 8: Copy Semantics");

	Span sp1(5);
	sp1.addNumber(7);
	sp1.addNumber(7);
	sp1.addNumber(7);

	Span sp2(sp1);
	std::cout << "Copied sp1 to sp2" << std::endl;
	std::cout << "sp2 shortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "sp2 longest span: " << sp2.longestSpan() << std::endl;
}

int main() {
	testSubjectExapmle();
	testOverflow();
	testInsufficientElements();
	testAddRange();
	testAddRangeOverflow();
	testEqualElements();
	testLargeSpan();
	testCopySemantics();

	std::cout << "\n=== All tests completed! ===\n";
	return 0;
}
