//
// Created by ganch on 05.11.2024.
//

#ifndef FLOAT_HPP
#define FLOAT_HPP

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <ostream>

#include "Common.hpp"

namespace types {

template<concepts::isFloat T>
class Float
{
private:
    T _value;

    template<concepts::isNatural T1>
    static constexpr T convertTypes(const T1& type)
    {
        return static_cast<T>(type);
    }

    // [[nodiscard]] static constexpr Float circumcisionOfValue(const Float& val)
    // {
    //     if (val > max())
    //         return static_cast<Float>(max());
    //
    //     if (val < max() && val < min())
    //         return static_cast<Float>(min());
    //
    //     return static_cast<Float>(val);
    // }

public:
    constexpr Float() : _value(0) {}

    template<concepts::isFloat T1>
    explicit Float(const T1& fl) : _value(fl) {}

    template<concepts::isFloat T1>
    constexpr explicit Float(T1&& fl)
        : _value(std::forward<T1>(fl)) {}

    template<concepts::isObjectIntAndNatural T1>
    constexpr explicit Float(const T1& num)
        : _value(static_cast<int64_t>(num)) {}

    template<concepts::isObjectIntAndNatural T1>
    constexpr explicit Float(T1&& num)
        : _value(std::move(static_cast<int64_t>(num))) {}

    template<concepts::isNatural T1>
    explicit operator T1() const
    {
        return _value;
    }

    friend constexpr std::ostream& operator<<(std::ostream& os, const Float& other)
    {
        return os << other._value;
    }
    friend constexpr std::istream& operator>>(std::istream& os, Float& other)
    {
        return os >> other._value;
    }

    static constexpr Float max()
    {
        return static_cast<Float>(std::numeric_limits<T>::max());
    }
    static constexpr Float min()
    {
        return static_cast<Float>(std::numeric_limits<T>::min());
    }

    // write concept for floats types
    // template<typename T1>
    // constexpr Float operator+(const T1& other) const
    // {
    //     return static_cast<Float>(_value + static_cast<T>(other));
    // }

    template<typename T1>
    constexpr bool operator>(const T1& other) const
    {
        return _value > static_cast<T>(other);
    }

    template<typename T1>
    constexpr bool operator>=(const T1& other) const
    {
        return _value >= static_cast<T>(other);
    }

    template<typename T1>
    constexpr bool operator<(const T1& other) const
    {
        return _value < static_cast<T>(other);
    }

    template<typename T1>
    constexpr bool operator<=(const T1& other) const
    {
        return _value <= static_cast<T>(other);
    }

    template<typename T1>
    constexpr bool operator==(const T1& other) const
    {
        return _value == static_cast<T>(other);
    }

};

} // types

#endif //FLOAT_HPP
