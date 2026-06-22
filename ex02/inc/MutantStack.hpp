#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

/**
 * @brief MutantStack - thin wrapper around std::stack that exposes iterator access
 * @tparam T type of elements stored in the stack.
 * 
 * @details
 * This class inherits from `std::stack<T>` and exposes the underlying
 * container's iterator interface (begin/end, rbegin/rend) so the stack
 * can be iterated from bottom to top or in reverse without changing
 * LIFO semantics of push/pop/top.
 */
template <typename T>
class MutantStack : public std::stack<T> {
	public:
		// Underlying container type ised by std::stack
		typedef typename std::stack<T>::container_type container_type;

		// Iterator types forwarded from the underlying container
		typedef typename container_type::iterator iterator;
		typedef typename container_type::const_iterator const_iterator;
		typedef typename container_type::reverse_iterator reverse_iterator;
		typedef typename container_type::const_reverse_iterator const_reverse_iterator;

		MutantStack() = default;
		MutantStack(const MutantStack& other) = default;
		MutantStack& operator=(const MutantStack& other) = default;
		~MutantStack() = default;

		// iterator to the first element (bottom of the stack)
		iterator begin();
		// iterator to one-past-last element (top + 1)
		iterator end();
		// const overload of begin()
		const_iterator begin() const;
		// const overload of end()
		const_iterator end() const;

		// reverse iterator starting at the top of the stack
		reverse_iterator rbegin();
		// reverse iterator one-past-last in reverse traversal
		reverse_iterator rend();
		// const overload of rbegin()
		const_reverse_iterator rbegin() const;
		// const overload of rend()
		const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"

#endif
