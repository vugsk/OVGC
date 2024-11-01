
#include <algorithm>
#include <array>
#include <concepts>
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

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
    using rangeInt = std::pair<int32_t, int32_t>;
    using rangeIntType = std::pair<std::string, rangeInt>;
    using ratioOfIntTypes = std::pair<std::string, std::string>;

    #if __GNUC__
        static inline const std::vector<rangeIntType> VECTOR_RANGE_INT_TYPES
        {
            rangeIntType{"a", rangeInt{INT8_MIN, INT8_MAX}},
            rangeIntType{"i", rangeInt{INT32_MIN, INT32_MAX}},
            rangeIntType{"s", rangeInt{INT16_MIN, INT16_MAX}},
            rangeIntType{"t", rangeInt{0, UINT16_MAX}},
            rangeIntType{"j", rangeInt{0, UINT32_MAX}},
            rangeIntType{"h", rangeInt{0, UINT8_MAX}},
        };

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

    static inline const std::string TYPE_VALUE = typeid(T).name();

    T _value;

    static constexpr Int findsRangeOfIntegerType(const bool is)
    {
        const auto i = std::ranges::find_if(VECTOR_RANGE_INT_TYPES,
            [](const rangeIntType& idType) -> bool
        {
            return idType.first == TYPE_VALUE;
        });

        if (i != VECTOR_RANGE_INT_TYPES.end())
            return is ? i->second.second : i->second.first;
        return 0;
    }

    static constexpr bool isTypeInt8()
    {
        return TYPE_VALUE == VECTOR_RANGE_INT_TYPES[0].first ||
               TYPE_VALUE == VECTOR_RANGE_INT_TYPES[5].first;
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

    template<isNumber T1>
    constexpr Int& operator=(const Int<T1>& other)
    {
        if (this == &other)
            return *this;
        _value = other._value;
        return *this;
    }

    template<isNumber T1>
    constexpr Int& operator=(const T1& other)
    {
        _value = other;
        return *this;
    }

    template<isNumber T1>
    constexpr Int& operator=(Int<T1>&& other) noexcept
    {
        if (this == &other)
            return *this;
        _value = std::move(other._value);
        return *this;
    }

    template<isNumber T1>
    constexpr Int& operator=(T1&& other) noexcept
    {
        _value = std::forward<T1>(other);
        return *this;
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

    [[nodiscard]] static constexpr Int max()
    {
        constexpr auto IS_SIZE_TYPE_MAX = true;
        return findsRangeOfIntegerType(IS_SIZE_TYPE_MAX);
    }

    [[nodiscard]] static constexpr Int min()
    {
        constexpr auto IS_SIZE_TYPE_MIN = false;
        return findsRangeOfIntegerType(IS_SIZE_TYPE_MIN);
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
    int32 i{90};
    int16 k{i};

    std::cout << k << '\n';

    return 0;
}
