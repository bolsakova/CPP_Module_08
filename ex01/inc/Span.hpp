#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>

/**
 * @brief Template function that finds the first occurrence of a value
 * in a container of ints.
 */
template <typename T>
typename T::iterator easyfind(T& container, int value);

/**
 * @brief Template function that finds the first occurrence of a value
 * in a const container of ints.
 */
template <typename T>
typename T::const_iterator easyfind(const T& container, int value);


#endif
