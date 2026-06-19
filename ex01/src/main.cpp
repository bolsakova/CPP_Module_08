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
