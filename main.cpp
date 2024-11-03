
#include <algorithm>
#include <cmath>
#include <concepts>
#include <cstdint>
#include <functional>
#include <iostream>

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
    static constexpr bool IS_SIGNED = std::is_signed_v<T>;
    static inline const std::string TYPE_VALUE = typeid(T).name();

    T _value;

    static constexpr T calculatesSizeOfType()
    {
        return static_cast<T>(pow(2, []() -> double
        {
            switch (sizeof(_value))
            {
                case 1:  return !IS_SIGNED ? 8  : 7;
                case 2:  return !IS_SIGNED ? 16 : 15;
                case 4:  return !IS_SIGNED ? 32 : 31;
                case 8:  return !IS_SIGNED ? 64 : 63;
                default: return 0;
            }
        }()));
    }

    static constexpr bool isTypeInt8()
    {
        return getType() == "int8" || getType() == "uint8";
    }

    template<isNumber T1>
    static constexpr Int circumcisionOfValue(const Int<T1>& val)
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
        return equal<T1>(other, [](const T1& t) -> T1
        {
            return isObjectInt<T1> ? static_cast<T1>(t) : t;
        });
    }

    template<isObjectIntAndNumber T1>
    constexpr Int& operator=(T1&& other) noexcept
    {
        return equal<T1>(other, [](const T1& t) -> T1
        {
            return std::move(isObjectInt<T1> ? static_cast<T1>(t) : t);
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
        _value = circumcisionOfValue(Int<int32_t>(_value + val));
        return *this;
    }

    template<isObjectIntAndNumber T1>
    constexpr Int& operator-=(const T1& val)
    {
        _value = circumcisionOfValue(Int<int32_t>(_value - val));
        return *this;
    }

    template<isObjectIntAndNumber T1>
    constexpr Int& operator*=(const T1& val)
    {
        _value = circumcisionOfValue(Int<int32_t>(_value * val));
        return *this;
    }

    template<isObjectIntAndNumber T1>
    constexpr Int& operator/=(const T1& val)
    {
        _value = static_cast<int32_t>(val) == 0 ? static_cast<Int>(val)
                                                : circumcisionOfValue(Int<int32_t>(_value / val));
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

    [[nodiscard]] static constexpr Int<uint64_t> convertToUnsignedInt(const std::string& str)
    {
        if (str.empty())
            return Int<uint64_t>{};
        return static_cast<Int<uint64_t>>(std::stoull(str));
    }

    [[nodiscard]] static constexpr Int<int64_t> convertToSignedInt(const std::string& str)
    {
        if (str.empty())
            return Int<int64_t>{};
        return static_cast<Int<int64_t>>(std::stoll(str));
    }

    [[nodiscard]] constexpr Int<uint8_t> sizeValue() const
    {
        return static_cast<Int<uint8_t>>(sizeof(_value));
    }

    [[nodiscard]] constexpr Int<uint8_t> size() const
    {
        return static_cast<Int<uint8_t>>(sizeof(*this));
    }

    [[nodiscard]] static constexpr Int max()
    {
        return Int(calculatesSizeOfType() - 1);
    }

    [[nodiscard]] static constexpr Int min()
    {

        return Int(IS_SIGNED ? calculatesSizeOfType() * -1 : 0);
    }

    [[nodiscard]] static constexpr std::string getType()
    {
        #if __GNUC__
            switch (TYPE_VALUE[0])
            {
                case 'a': return "int8";
                case 's': return "int16";
                case 'i': return "int32";
                case 'x': return "int64";

                case 'h': return "uint8";
                case 't': return "uint16";
                case 'j': return "uint32";
                case 'y': return "uint64";

                default:  return std::string{};
            }
        #elif _MSV_VER
        #elif _clang_
        #elif __MINGW64__
        #endif
    }
};

using int32 = Int<int32_t>;
using int16 = Int<int16_t>;
using int8 = Int<int8_t>;
using int64 = Int<int64_t>;

using uint32 = Int<uint32_t>;
using uint16 = Int<uint16_t>;
using uint8 = Int<uint8_t>;
using uint64 = Int<uint64_t>;


int main()
{
    int8 op(89);
    std::cout << op << '\n';
    return 0;
}
