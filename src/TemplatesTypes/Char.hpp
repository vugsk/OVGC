//
// Created by ganch on 04.11.2024.
//

#ifndef CHAR_HPP
#define CHAR_HPP

#include <algorithm>
#include <cstdint>

#include "Common.hpp"

namespace types
{

template<concepts::isChar T>
class Char
{
private:
    T _value;

    template<typename F>
    [[nodiscard]] static constexpr Bool conditional(const T& a, const T& b, F&& func)
    {
        return func(a, b);
    }
    [[nodiscard]] static consteval Bool equals(const T& a, const T& b)
    {
        return static_cast<Bool>(a == b);
    }
    [[nodiscard]] static consteval Bool notEquals(const T& a, const T& b)
    {
        return static_cast<Bool>(a != b);
    }
    [[nodiscard]] static consteval Bool small(const T& a, const T& b)
    {
        return static_cast<Bool>(a < b);
    }
    [[nodiscard]] static consteval Bool big(const T& a, const T& b)
    {
        return static_cast<Bool>(a > b);
    }
    [[nodiscard]] static consteval Bool smallAndEquals(const T& a, const T& b)
    {
        return static_cast<Bool>(a <= b);
    }
    [[nodiscard]] static consteval Bool bigAndEquals(const T& a, const T& b)
    {
        return static_cast<Bool>(a >= b);
    }

public:
    constexpr Char() : _value(0) {}

    template<concepts::isChar T1>
    constexpr explicit Char(const T1& simbol)
        : _value(simbol) {}

    template<concepts::isChar T1>
    constexpr explicit Char(T1&& simbol)
        : _value(std::forward<T1>(simbol)) {}

    template<concepts::isObjectTypeOrNatural T1>
    constexpr explicit Char(const T1& number)
        : _value(static_cast<int64_t>(number)) {}

    template<concepts::isObjectTypeOrNatural T1>
    constexpr explicit Char(T1&& number)
        : _value(std::move(static_cast<int64_t>(number))) {}

    template<concepts::isObjectTypes T1>
    explicit operator T1() const
    {
        return static_cast<T1>(_value);
    }

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

    template<concepts::isObjectTypes T1>
    constexpr Bool operator>(const T1& other) const
    {
        return conditional(_value, static_cast<T>(other), big);
    }

    template<concepts::isObjectTypes T1>
    constexpr Bool operator<(const T1& other) const
    {
        return conditional(_value, static_cast<T>(other), small);
    }

    template<concepts::isObjectTypes T1>
    constexpr Bool operator>=(const T1& other) const
    {
        return conditional(_value, static_cast<T>(other), bigAndEquals);
    }

    template<concepts::isObjectTypes T1>
    constexpr Bool operator<=(const T1& other) const
    {
        return conditional(_value, static_cast<T>(other), smallAndEquals);
    }

    template<concepts::isObjectTypes T1>
    constexpr Bool operator==(const T1& other) const
    {
        return conditional(_value, static_cast<T>(other), equals);
    }

    template<concepts::isObjectTypes T1>
    constexpr Bool operator!=(const T1& other) const
    {
        return conditional(_value, static_cast<T>(other), notEquals);
    }

    template<concepts::isObjectTypes T1>
    constexpr Char& operator=(const T1& other)
    {
        _value = static_cast<T>(other);
        return *this;
    }

    template<concepts::isObjectTypes T1>
    constexpr Char& operator=(T1&& other)
    {
        _value = std::move(static_cast<T>(other));
        return *this;
    }

};

} // types

#endif //CHAR_HPP
