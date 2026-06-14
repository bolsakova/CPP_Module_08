#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include <algorithm>

/**
 * @brief Find the first element that is equal to value.
 * @tparam T Container type.
 * @param container Container to search.
 * @param value Integer to find.
 * @return Iterator to the first matching element.
 * @throws std::exception if the element is not found.
 */
template <typename T>
typename T::iterator easyfind(T& container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);

	// std::find returns end() when the value is not present
	if (it == container.end())
		throw std::exception();
	
		return it;
}

/**
 * @brief Template function that finds the first occurrence of a value
 * in a const container of ints.
 */
template <typename T>
typename T::const_iterator easyfind(const T& container, int value) {

}

#endif
