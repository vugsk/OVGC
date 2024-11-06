//
// Created by ganch on 04.11.2024.
//

#ifndef COMMON_HPP
#define COMMON_HPP

#include <concepts>


namespace concepts
{

template<typename T>
concept isChar = std::is_same_v<std::decay_t<T>, char8_t> ||
                 std::is_same_v<std::decay_t<T>, char16_t> ||
                 std::is_same_v<std::decay_t<T>, char32_t>;

template<typename T>
concept isFloat = std::floating_point<T>;

template<typename T>
concept isNumber = std::integral<T> && !isChar<T>;

template<typename T>
concept isNatural = isNumber<T> || isFloat<T>;

template<typename T>
concept isObjectInt = std::is_object_v<T> || T::getType();

template<typename T>
concept isObjectIntAndNatural = isObjectInt<T> || isNatural<T>;

template<typename T>
concept isObjectIntAndNumber = isObjectInt<T> || isNumber<T>;

}

namespace utils
{



} // utils

#endif //COMMON_HPP
