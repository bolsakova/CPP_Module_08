#include "../inc/Span.hpp"
#include <iostream>
#include <vector>
#include <random>

static void printHeader(const char* title) {
	std::cout << "\n=== " << title << " ===\n";
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

int main() {
	testSubjectExapmle();
	testOverflow();
	testInsufficientElements();
	testAddRange();
	testAddRangeOverflow();
	testEqualElements();
	testLargeSpan();
	testCopySemantics();
	return 0;
}
