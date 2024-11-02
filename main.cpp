
#include <algorithm>
#include <array>
#include <cmath>
#include <concepts>
#include <cstdint>
#include <functional>
#include <iostream>
#include <map>

template<typename T>
concept isNumber = std::integral<T>;

template<typename T>
concept isObjectInt = std::is_object_v<T> || T::getType();

template<typename T>
concept isObjectIntAndNumber = isObjectInt<T> || isNumber<T>;

template<isNumber T>
class Int
{
protected:
    using ratioOfIntTypes = std::pair<std::string, std::string>;

    #if __GNUC__
        static constexpr uint8_t SIZE_ARRAY_INT_TYPES = 6;
        static inline const std::array<ratioOfIntTypes, SIZE_ARRAY_INT_TYPES> ARRAY_INT_TYPES
        {
            ratioOfIntTypes("a", "int8_t"),
            ratioOfIntTypes("i", "int32_t"),
            ratioOfIntTypes("s", "int16_t"),
            ratioOfIntTypes("t", "uint16_t"),
            ratioOfIntTypes("j", "uint32_t"),
            ratioOfIntTypes("h", "uint8_t"),
        };
    #elif _MSV_VER
    #elif _clang_
    #elif __MINGW64__
    #endif

    static constexpr uint8_t ter()
    {
        switch (sizeof(_value))
        {
            case 1:
                return isSigned ? 8 : 7;
            case 2:
                return isSigned ? 16 : 15;
            case 4:
                return isSigned ? 32 : 31;
            default:
                return 0;
        }
    }

    static constexpr bool isSigned = std::is_signed_v<T>;
    static inline const std::string TYPE_VALUE = typeid(T).name();
    static constexpr int64_t ioo = static_cast<int64_t>(pow(2, ter()));

    T _value;

    static constexpr bool isTypeInt8()
    {
        return TYPE_VALUE == std::string{"a"} || TYPE_VALUE == std::string{"h"};
    }

    template<isNumber T1>
    static constexpr Int ty(const Int<T1>& val)
    {
        if (val > max())
            return max();

        if (val < max() && val < min())
            return min();

        return static_cast<Int>(val);
    }

    template<isObjectIntAndNumber T1>
    constexpr Int& equal(const T1& other, const std::function<T1(T1)>& func)
    {
        if (isObjectInt<T1> && *this == other)
            return *this;

        _value = func(other);
        return *this;
    }

    template<isObjectInt T1>
    static constexpr T1 tp(const T1& t)
    {
        return isObjectInt<T1> ? static_cast<T1>(t) : t;
    }

public:
    Int() : _value(0) {}
    explicit Int(const T& val) : _value(val) {}
    explicit Int(T&& val) : _value(val) {}
    Int(const Int& other) = default;
    Int(Int&& other) noexcept : _value{std::move(other._value)} {}
    ~Int() = default;

    template<isNumber T1>
    explicit Int(const Int<T1>& other) : _value(static_cast<T1>(other)) {}

    template<isNumber T1>
    explicit Int(Int<T1>&& other) : _value(static_cast<T1>(std::move(other))) {}

    template<isObjectIntAndNumber T1>
    constexpr Int& operator=(const T1& other)
    {
        return equal<T1>(other, tp<T1>);
    }

    template<isObjectIntAndNumber T1>
    constexpr Int& operator=(T1&& other) noexcept
    {
        return equal<T1>(other, [](const T1& t) -> T1
        {
            return std::move(tp<T1>(t));
        });
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


    template<isObjectIntAndNumber T1>
    constexpr Int& operator+=(const T1& val)
    {
        _value = ty(Int<int32_t>(_value + val));
        return *this;
    }

    template<isObjectIntAndNumber T1>
    constexpr Int& operator-=(const T1& val)
    {
        _value = ty(Int<int32_t>(_value - val));
        return *this;
    }

    template<isObjectIntAndNumber T1>
    constexpr Int& operator*=(const T1& val)
    {
        _value = ty(Int<int32_t>(_value * val));
        return *this;
    }

    template<isObjectIntAndNumber T1>
    constexpr Int& operator/=(const T1& val)
    {
        _value = static_cast<int32_t>(val) == 0 ? static_cast<Int>(val) : ty(Int<int32_t>(_value / val));
        return *this;
    }

    friend constexpr std::ostream& operator<<(std::ostream& os, const Int& other)
    {
        return os << (isTypeInt8() ? static_cast<int16_t>(other._value) : other._value);
    }

    operator T() const
    {
        return isTypeInt8() ? static_cast<int16_t>(_value) : _value;
    }

    [[nodiscard]] std::string convertToString() const
    {
        return std::to_string(_value);
    }

    [[nodiscard]] static constexpr Int<int32_t> convertToInt(const std::string& str)
    {
        return static_cast<Int<int32_t>>(std::stoi(str));
    }

    [[nodiscard]] constexpr Int<uint8_t> sizeValue() const
    {
        return static_cast<Int<uint8_t>>(sizeof(_value));
    }

    [[nodiscard]] constexpr Int<uint8_t> size() const
    {
        return static_cast<Int<uint8_t>>(sizeof(*this));
    }

    [[nodiscard]] static constexpr Int<int64_t> max()
    {
        return Int<int64_t>(ioo - 1);
    }

    [[nodiscard]] static constexpr Int<int64_t> min()
    {
        return Int<int64_t>(isSigned ? ioo * -1 : 0);
    }

    [[nodiscard]] static constexpr std::string getType()
    {
        const auto i = std::ranges::find_if(ARRAY_INT_TYPES,
            [](const std::pair<std::string, std::string>& si) -> bool
        {
            return si.first == TYPE_VALUE;
        });
        if (i != ARRAY_INT_TYPES.end())
            return i->second;
        return std::string{};
    }

};

using int32 = Int<int32_t>;
using int16 = Int<int16_t>;
using int8 = Int<int8_t>;

using uint32 = Int<uint32_t>;
using uint16 = Int<uint16_t>;
using uint8 = Int<uint8_t>;


int main()
{
    uint32 i{90};
    std::cout << i.max() << ' ' << i.min() << '\n';
    return 0;
}
