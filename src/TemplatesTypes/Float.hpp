//
// Created by ganch on 05.11.2024.
//

#ifndef FLOAT_HPP
#define FLOAT_HPP

#include <algorithm>
#include <cstdint>
#include <float.h>
#include <ostream>

#include "Common.hpp"

namespace types {

template<concepts::isFloat T>
class Float {
private:
    T _value;

    template<concepts::isNatural T1>
    static constexpr T convertTypes(const Float<T1>& type)
    {
        return static_cast<T>(type);
    }

public:
    Float() : _value(0) {}
    template<concepts::isObjectIntAndNatural T1>
    explicit Float(const T1& num) : _value(static_cast<int32_t>(num)) {}

    template<concepts::isObjectIntAndNatural T1>
    explicit Float(T1&& num) : _value(std::move(static_cast<int32_t>(num))) {}

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

    // template<concepts::isObjectIntAndNatural T1>
    // [[nodiscard]] constexpr Float operator+(const T1& val) const
    // {
    //     return Float(circumcisionOfValue(Int<int64_t>(_value + convertTypes(val))));
    // }
    //
    // template<concepts::isObjectIntAndNatural T1>
    // [[nodiscard]] constexpr Float operator-(const T1& val) const
    // {
    //     return Float(circumcisionOfValue(Int<int64_t>(_value - convertTypes(val))));
    // }
    //
    // template<concepts::isObjectIntAndNatural T1>
    // [[nodiscard]] constexpr Float operator/(const T1& val) const
    // {
    //     return static_cast<float>(val)
    //         ? Float(circumcisionOfValue(Int<int64_t>(_value / convertTypes(val))))
    //         : Float{};
    // }



};

} // types

#endif //FLOAT_HPP
