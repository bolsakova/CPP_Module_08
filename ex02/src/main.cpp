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
	ms.push(3);
	ms.push(5);
	ms.push(737);
	ms.push(0);
	
	// iterate from bottom -> top
	std::cout << "forward iteration: ";
	for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
		std::cout << *it << ' ';
	std::cout << '\n';

	// reverse iteration from top -> bottom
	std::cout << "reverse iteration: ";
	for (MutantStack<int>::reverse_iterator rit = ms.rbegin(); rit != ms.rend(); ++rit)
		std::cout << *rit << ' ';
	std::cout << '\n';

	// const iteration test
	const MutantStack<int>& cms = ms;
	std::cout << "const forward iteration: ";
	for (MutantStack<int>::const_iterator it = cms.begin(); it != cms.end(); ++it)
		std::cout << *it << ' ';
	std::cout << '\n';

	// const reverse iteration
	std::cout << "const reverse iteration: ";
	for (MutantStack<int>::const_reverse_iterator crit = cms.rbegin(); crit != cms.rend(); ++crit)
		std::cout << *crit << ' ';
	std::cout << '\n';

	// compatibility test: MutantStack is a std::stack
	std::stack<int> s(ms);
	std::cout << "copy to std::stack top: " << s.top() << '\n';

	std::cout << "\n=== All tests completed! ===\n";
	return 0;
}
