//
// Created by ganch on 05.11.2024.
//

#ifndef FLOAT_HPP
#define FLOAT_HPP

#include <algorithm>
#include <cstdint>

#include "Bool.hpp"
#include "Common.hpp"
#include "Int.hpp"


namespace types
{

template<concepts::isFloat T>
class Float
{
private:
    enum TYPES : uint8_t
    {
        NONE = 0,
        FLOAT = 1,
        DOUBLE = 2,
        LONG_DOUBLE = 3,
    };

    T _value;

    [[nodiscard]] static constexpr Float circumcisionOfValue(const Float& val)
    {
        if (val > max())
            return static_cast<Float>(max());

        if (val < max() && val < min())
            return static_cast<Float>(min());

        return static_cast<Float>(val);
    }

    [[nodiscard]] static consteval TYPES types()
    {
        if constexpr (std::is_same_v<std::decay_t<T>, float>)
            return FLOAT;
        else if constexpr (std::is_same_v<std::decay_t<T>, double>)
            return DOUBLE;
        else if constexpr (std::is_same_v<std::decay_t<T>, long double>)
            return LONG_DOUBLE;
        else
            return NONE;
    }

    template<typename T1 = Float, typename F>
    [[nodiscard]] static constexpr T1 opration(const T& a, const T& b, F&& func)
    {
        if constexpr (std::is_same_v<T1, Float>)
            return circumcisionOfValue(func(b, a));
        else
            return static_cast<T>(circumcisionOfValue(func(a, b)));
    }
    [[nodiscard]] static consteval Float plus(const T& a, const T& b)
    {
        return static_cast<Float>(a + b);
    }
    [[nodiscard]] static consteval Float minus(const T& a, const T& b)
    {
        return static_cast<Float>(a - b);
    }
    [[nodiscard]] static consteval Float mul(const T& a, const T& b)
    {
        return static_cast<Float>(a * b);
    }
    [[nodiscard]] static consteval Float dis(const T& a, const T& b)
    {
        return static_cast<Float>(a / b);
    }

public:
    constexpr Float() : _value(0) {}

    template<concepts::isFloat T1>
    explicit Float(const T1& fl) : _value(fl) {}

    template<concepts::isFloat T1>
    constexpr explicit Float(T1&& fl)
        : _value(std::forward<T1>(fl)) {}

    template<concepts::isObjectTypeOrNatural T1>
    constexpr explicit Float(const T1& num)
        : _value(static_cast<int64_t>(num)) {}

    template<concepts::isObjectTypeOrNatural T1>
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

    [[nodiscard]] static constexpr Int<uint8_t> size()
    {
        return static_cast<Int<uint8_t>>(sizeof(Float));
    }
    [[nodiscard]] static constexpr Int<uint8_t> sizeValue()
    {
        return static_cast<Int<uint8_t>>(sizeof(_value));
    }
    [[nodiscard]] static constexpr Float max()
    {
        return static_cast<Float>(std::numeric_limits<T>::max());
    }
    [[nodiscard]] static constexpr Float min()
    {
        return static_cast<Float>(std::numeric_limits<T>::min());
    }

    // write concept for floats types
    template<concepts::isObjectType T1>
    [[nodiscard]] constexpr Bool operator>(const T1& other) const
    {
        return static_cast<Bool>(_value > static_cast<T>(other));
    }

    template<concepts::isObjectType T1>
    [[nodiscard]] constexpr Bool operator>=(const T1& other) const
    {
        return static_cast<Bool>(_value >= static_cast<T>(other));
    }

    template<concepts::isObjectType T1>
    [[nodiscard]] constexpr Bool operator<(const T1& other) const
    {
        return static_cast<Bool>(_value < static_cast<T>(other));
    }

    template<concepts::isObjectType T1>
    [[nodiscard]] constexpr Bool operator<=(const T1& other) const
    {
        return static_cast<Bool>(_value <= static_cast<T>(other));
    }

    template<concepts::isObjectType T1>
    [[nodiscard]] constexpr Bool operator==(const T1& other) const
    {
        return static_cast<Bool>(_value == static_cast<T>(other));
    }

    template<concepts::isObjectType T1>
    [[nodiscard]] constexpr Bool operator!=(const T1& other) const
    {
        return static_cast<Bool>(_value != static_cast<T>(other));
    }

    template<concepts::isObjectType T1>
    [[nodiscard]] constexpr Float operator+(const T1& other) const
    {
        return opration(static_cast<T>(other), _value, plus);
    }

    template<concepts::isObjectType T1>
    [[nodiscard]] constexpr Float operator-(const T1& other) const
    {
        return opration(static_cast<T>(other), _value, minus);
    }

    template<concepts::isObjectType T1>
    [[nodiscard]] constexpr Float operator*(const T1& other) const
    {
        return opration(static_cast<T>(other), _value, mul);
    }

    template<concepts::isObjectType T1>
    [[nodiscard]] constexpr Float operator/(const T1& other) const
    {
        return static_cast<int8_t>(other)
            ? opration(static_cast<T>(other), _value, dis)
            : Float{};
    }

    template<concepts::isObjectType T1>
    constexpr Float& operator+=(const T1& other)
    {
        _value = opration<T>(static_cast<T>(other), _value, plus);
        return *this;
    }

    template<concepts::isObjectType T1>
    constexpr Float& operator-=(const T1& other)
    {
        _value = opration<T>(static_cast<T>(other), _value, minus);
        return *this;
    }

    template<concepts::isObjectType T1>
    constexpr Float& operator*=(const T1& other)
    {
        _value = opration<T>(static_cast<T>(other), _value, mul);
        return *this;
    }

    template<concepts::isObjectType T1>
    constexpr Float& operator/=(const T1& other)
    {
        _value = static_cast<T>(other)
            ? opration<T>(static_cast<T>(other), _value, dis)
            : T{};
        return *this;
    }

    constexpr Float& operator++()
    {
        ++_value;
        return *this;
    }
    constexpr Float operator++(int)
    {
        Float tmp{*this};
        ++_value;
        return tmp;
    }
    constexpr Float& operator--()
    {
        --_value;
        return *this;
    }
    constexpr Float operator--(int)
    {
        Float tmp{*this};
        --_value;
        return tmp;
    }

    [[nodiscard]] static constexpr std::string getType()
    {
        switch (types())
        {
            case FLOAT: return "float32";
            case DOUBLE: return "float64";
            case LONG_DOUBLE: return "float128";
            default:  return std::string{};
        }
    }

    [[nodiscard]] std::string convertToString() const
    {
        return std::to_string(_value);
    }

};

} // types

#endif //FLOAT_HPP
