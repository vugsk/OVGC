

#include <cstdint>
#include <iostream>
#include <ostream>

template<typename T>
concept isNumber = std::integral<T>;

template<isNumber T>
class Int
{
protected:
    T _value;

public:
    Int() : _value(0) {}
    Int(const Int& other) : _value(other._value) {}
    Int(Int&& other) noexcept : _value(other._value) {}
    Int(const T& value) : _value(value) {}
    Int(T&& value) : _value(value) {}
    virtual  ~Int() = default;

    Int& operator=(const Int& other)
    {
        if (this == &other)
            return *this;
        _value = other._value;
        return *this;
    }
    Int& operator=(Int&& other) noexcept
    {
        if (this == &other)
            return *this;
        _value = other._value;
        return *this;
    }

    bool operator==(const Int& lhs) const
    {
        return lhs._value == _value;
    }

    bool operator!=(const Int& lhs) const
    {
        return !(lhs == _value);
    }

    bool operator>(const Int& lhs) const
    {
        return _value < lhs._value;
    }

    bool operator<=(const Int& lhs) const
    {
        return !(_value < lhs._value);
    }

    bool operator>=(const Int& lhs) const
    {
        return !(lhs._value < _value);
    }

    friend std::ostream& operator<<(std::ostream& os, const Int& obj)
    {
        return os << obj._value;
    }

    Int& operator++()
    {
        ++_value;
        return *this;
    }

    Int operator++(int)
    {
        Int temp(*this);
        ++_value;
        return temp;
    }

    Int& operator--()
    {
        --_value;
        return *this;
    }

    Int operator--(int)
    {
        Int temp = *this;
        --_value;
        return temp;
    }

    Int& operator+=(const Int& val)
    {
        _value += val._value;
        return *this;
    }

    Int& operator-=(const Int& val)
    {
        _value -= val._value;
        return *this;
    }

    Int& operator*=(const Int& val)
    {
        _value *= val._value;
        return *this;
    }

    Int& operator/=(const Int& val)
    {
        _value /= val._value;
        return *this;
    }

    Int operator+(const Int& val) const
    {
        return _value + val._value;
    }

    Int operator-(const Int& val) const
    {
        return _value - val._value;
    }

    Int operator*(const Int& val) const
    {
        return _value * val._value;
    }

    Int operator/(const Int& val) const
    {
        return _value / val._value;
    }




    std::strong_ordering operator<=>(const Int& other) const
    {
        if (_value < other._value)
            return std::strong_ordering::less;
        else if (_value > other._value)
            return std::strong_ordering::greater;
        else
            return std::strong_ordering::equal;
    }

    operator T() const
    {
        return _value;
    }

    [[nodiscard]] constexpr T getValue() const
    {
        return _value;
    }

    [[nodiscard]] std::string convertToString() const
    {
        return std::to_string(_value);
    }

    [[nodiscard]] static constexpr Int convertToInt(const std::string& str)
    {
        return static_cast<Int>(std::stoi(str));
    }

    [[nodiscard]] constexpr Int<int16_t> size() const
    {
        return static_cast<Int<int16_t>>(sizeof(_value));
    }

    [[nodiscard]] virtual Int max() const { return static_cast<Int>(0); }
    [[nodiscard]] virtual Int min() const { return static_cast<Int>(0); }

};

class Int32 final : public Int<int32_t>
{
public:
    Int32() = default;
    Int32(const Int& other) : Int(other) {}
    Int32(Int&& other) : Int(other) {}
    Int32(const int32_t& value) : Int(value) {}
    Int32(int32_t&& value) : Int(value) {}
    Int32(const Int32& other) = default;
    Int32(Int32&& other) noexcept : Int(std::move(other)) {}
    ~Int32() override = default;

    Int32& operator=(const Int32& other)
    {
        if (this == &other)
            return *this;
        Int::operator =(other);
        return *this;
    }

    Int32& operator=(Int32&& other) noexcept
    {
        if (this == &other)
            return *this;
        Int::operator =(std::move(other));
        return *this;
    }

    [[nodiscard]] Int max() const override
    {
        return static_cast<Int>(INT32_MAX);
    }

    [[nodiscard]] Int min() const override
    {
        return static_cast<Int>(INT32_MIN);
    }
};

class Int8 final : public Int<int8_t>
{
public:
    Int8() = default;
    Int8(const Int& other) : Int(other) {}
    Int8(Int&& other) : Int(other) {}
    Int8(const int8_t& value) : Int(value) {}
    Int8(int8_t&& value) : Int(value) {}
    Int8(const Int8& other) = default;
    Int8(Int8&& other) noexcept : Int(std::move(other)) {}
    ~Int8() override = default;

    Int8& operator=(const Int8& other)
    {
        if (this == &other)
            return *this;
        Int::operator =(other);
        return *this;
    }

    Int8& operator=(Int8&& other) noexcept
    {
        if (this == &other)
            return *this;
        Int::operator =(std::move(other));
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Int8& obj)
    {
        return os << static_cast<Int<int16_t>>(obj._value);
    }

    // Int<int16_t> operator+(const Int<int16_t>& val) const
    // {
    //     return static_cast<Int<int16_t>>(static_cast<int16_t>(_value + val.getValue()));
    // }
    // Int<int16_t> operator-(const Int<int16_t>& val) const
    // {
    //     return static_cast<Int<int16_t>>(static_cast<int16_t>(_value - val.getValue()));
    // }
    // Int<int16_t> operator*(const Int<int16_t>& val) const
    // {
    //     return static_cast<Int<int16_t>>(static_cast<int16_t>(_value * val.getValue()));
    // }
    // Int<int16_t> operator/(const Int<int16_t>& val) const
    // {
    //     return static_cast<Int<int16_t>>(static_cast<int16_t>(_value / val.getValue()));
    // }

    [[nodiscard]] Int max() const override
    {
        return static_cast<Int>(INT8_MAX);
    }
    [[nodiscard]] Int min() const override
    {
        return static_cast<Int>(INT8_MIN);
    }

};
