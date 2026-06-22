#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

/**
 * std::stack<T> hides its container in a protected member 'c'.
 * Because MutantStack inherits std::stack, it can access 'this->c'.
 * The methods below simply forward to the underlying container's
 * iterator methods so callers can iterate the stack contents.
 */

// Non-const iterators

/**
 * @brief Returns iterator to the first element (bottom of stack)
 * @tparam T element type.
 * @return iterator pointing to the first element of the underlying container.
 */
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

/**
 * @brief Returns iterator to one-past-last element
 * @tparam T element type.
 * @return iterator pointing to the first element of the underlying container.
 */
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}

// Const iterators

/**
 * @brief Const version of begin().
 * @tparam T Element type.
 * @return const_iterator to the beginning of the underlying container.
 */
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
	return this->c.begin();
}

/**
 * @brief Const version of end().
 * @tparam T Element type.
 * @return const_iterator to the end of the underlying container.
 */
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
	return this->c.end();
}

// Reverse iterators

/**
 * @brief Return reverse iterator starting at the top of the stack.
 * @tparam T Element type.
 * @return reverse_iterator pointing to the first element in reverse order.
 */
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
	return this->c.rbegin();
}

/**
 * @brief Return reverse iterator one-past-last in reverse traversal.
 * @tparam T Element type.
 * @return reverse_iterator pointing to the end of reverse traversal.
 */
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
	return this->c.rend();
}

// Const reverse iterators

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const {}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const {}

#endif
