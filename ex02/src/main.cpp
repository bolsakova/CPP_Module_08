#include "../inc/MutantStack.hpp"
#include <iostream>
#include <stack>

int main() {
	// Basic push/pop/top/size test
	MutantStack<int> ms;
	ms.push(5);
	ms.push(17);
	std::cout << "top: " << ms.top() << '\n'; // 17
	
	ms.pop();
	std::cout << "size after pop: " << ms.size() << '\n'; // 1

	// fill with more values

	// iterate from bottom -> top

	// reverse iteration from top -> bottom

	// const iteration test

	// compatibility test: MutantStack is a std::stack

	std::cout << "\n=== All tests completed! ===\n";
	return 0;
}
