//
// Created by nikita on 05.04.25.
//

#ifndef RESTRICTIONSFORTYPES_HPP
#define RESTRICTIONSFORTYPES_HPP

namespace restrictions_for_templates::types
{

template<typename T>
concept isChar = std::is_same_v<T, char8_t> ||
        std::is_same_v<T, char16_t> ||
        std::is_same_v<T, char32_t>;

template<typename T>
concept isNumber = std::is_integral_v<T> && !isChar<T>;

}

#endif //RESTRICTIONSFORTYPES_HPP
