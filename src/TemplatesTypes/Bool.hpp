//
// Created by nikita on 11.01.25.
//

#ifndef BOOL_HPP
#define BOOL_HPP


#include <algorithm>
#include <bitset>

#include "Common.hpp"


namespace types
{

class Bool
{
private:
    std::bitset<1> _value;

    template<typename T>
    static constexpr std::bitset<1> ui(const T& value)
    {
        return std::bitset<1>(value >= 1 ? 1 : 0);
    }

public:
    constexpr Bool() : _value(0) {}
    constexpr explicit Bool(const bool value)
        : _value(static_cast<std::bitset<1>>(value)) {}

    template<concepts::isObjectTypeOrNatural T>
    constexpr explicit Bool(const T& value)
        : _value(ui(value)) {}

    template<concepts::isObjectTypeOrNatural T>
    constexpr explicit Bool(T&& value)
        : _value(ui(std::move(value))) {}

    constexpr Bool(const Bool& other)
        : _value(other._value) {}
    constexpr Bool(Bool&& other) noexcept
        : _value(std::move(other._value)) {}

    template<concepts::isObjectTypeOrNatural T>
    constexpr Bool& operator=(const T& other)
    {
        _value = ui(other);
        return *this;
    }

    template<concepts::isObjectTypeOrNatural T>
    constexpr Bool& operator=(T&& other) noexcept
    {
        _value = ui(std::move(other));
        return *this;
    }

    template<concepts::isObjectTypeOrNatural T>
    explicit operator T() const
    {
        return static_cast<T>(_value.to_ulong());
    }

    friend constexpr std::ostream& operator<<(std::ostream& os, const Bool& other)
    {
        return os << (other._value.all() ? "true" : "false");
    }

    // error
    // friend constexpr std::istream& operator>>(std::istream& os, Bool& other)
    // {
    //     return os >> other._value.to_ulong();
    // }

    template<concepts::isObjectTypeOrNatural T>
    constexpr Bool operator==(const T& val) const
    {
        return _value == ui(val);
    }

    template<concepts::isObjectTypeOrNatural T>
    constexpr Bool operator!=(const T& val) const
    {
        return _value != ui(val);
    }

    template<concepts::isObjectTypeOrNatural T>
    constexpr Bool operator>(const T& val) const
    {
        return _value > ui(val);
    }

    template<concepts::isObjectTypeOrNatural T>
    constexpr Bool operator<(const T& val) const
    {
        return _value < ui(val);
    }

    template<concepts::isObjectTypeOrNatural T>
    constexpr Bool operator>=(const T& val) const
    {
        return _value >= ui(val);
    }

    template<concepts::isObjectTypeOrNatural T>
    constexpr Bool operator<=(const T& val) const
    {
        return _value <= ui(val);
    }

};

}

#endif //BOOL_HPP
