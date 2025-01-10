//
// Created by ganch on 04.11.2024.
//

#ifndef CHAR_HPP
#define CHAR_HPP

#include <algorithm>
#include <cstdint>
#include <iostream>


#include "Common.hpp"

namespace types
{
// не работает, в windows кал
template<concepts::isChar T>
class Char {
private:
    T _value;

public:
    Char() : _value(0) {}

    template<concepts::isChar T1>
    explicit Char(const T1& simbol) : _value(simbol) {}

    template<concepts::isChar T1>
    explicit Char(T1&& simbol) : _value(std::forward<T1>(simbol)) {}

    template<concepts::isObjectIntAndNumber T1>
    explicit Char(const T1& number) : _value(static_cast<int32_t>(number)) {}

    template<concepts::isObjectIntAndNumber T1>
    explicit Char(T1&& number)
        : _value(std::forward<T1>(static_cast<int32_t>(number))) {}


    friend constexpr std::wostream& operator<<(std::wostream& os, const Char& other)
    {
        return os << static_cast<wchar_t>(other._value);
    }

    friend constexpr std::wistream& operator>>(std::wistream& os, Char& other)
    {
        wchar_t i;
        os >> i;
        other._value = i;
        return os;
    }
};

} // types

#endif //CHAR_HPP
