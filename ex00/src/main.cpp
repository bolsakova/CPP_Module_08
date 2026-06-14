#include "../inc/easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

/**
 * @brief Print a section heading for test output.
 */
static void printHeadline(const char* title) {
	std::cout << "=== " << title << " ===" << std::endl;
}

/**
 * @brief This test checks:
 * - successful search for an existing value
 * - exception handling when the value is missing
 */
static void runTestVector() {
	printHeadline("vector<int> test");

	std::vector<int> numbers = {10, 20, 30, 40, 50};
	try {
		auto it = easyfind(numbers, 30);
		std::cout << "Found value: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Value 30 not found" << std::endl;
	}

	try {
		auto it = easyfind(numbers, 99);
		std::cout << "Found value: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Value 99 not found" << std::endl;
	}
}

int main() {
	runTestVector();
	runTestList();
	runTestConstVector();
	return 0;
}
