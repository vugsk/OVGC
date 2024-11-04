
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
private:
    enum TYPES : uint8_t
    {
        NONE,
        INT8,
        INT16,
        INT32,
        INT64,
        UINT8,
        UINT16,
        UINT32,
        UINT64,
    };

    static constexpr bool IS_SIGNED = std::is_signed_v<T>;
    static inline const std::string TYPE_VALUE = typeid(T).name();

    T _value;


    [[nodiscard]] static constexpr T calculatesSizeOfType()
    {
        return static_cast<T>(pow(2, []() -> double
        {
            switch (sizeof(T))
            {
                case 1:  return !IS_SIGNED ? 8  : 7;
                case 2:  return !IS_SIGNED ? 16 : 15;
                case 4:  return !IS_SIGNED ? 32 : 31;
                case 8:  return !IS_SIGNED ? 64 : 63;
                default: return 0;
            }
        }()));
    }
    // compilation
    [[nodiscard]] static consteval bool isTypeInt8()
    {
        return types() == INT8 || types() == UINT8;
    }


    template<isNumber T1>
    [[nodiscard]] static constexpr T circumcisionOfValue(const Int<T1>& val)
    {
        if (val > max())
            return convertTypes(max());

        if (val < max() && val < min())
            return convertTypes(min());

        return convertTypes(val);
    }

    template<isObjectInt T1>
    [[nodiscard]] static constexpr T convertTypes(const T1& type)
    {
        return static_cast<T>(type);
    }

    // compilation
    template<isNumber T1>
    [[nodiscard]] static consteval std::istream& inputFromStream(std::istream& os, Int<T1>& other)
    {
        int64_t i;
        os >> i;
        other = static_cast<T1>(circumcisionOfValue(Int(i)));
        return os;
    }

    // compilation
    [[nodiscard]] static consteval TYPES types()
    {
        if constexpr (std::is_same_v<std::decay_t<T>, int8_t>)
            return INT8;
        else if constexpr (std::is_same_v<std::decay_t<T>, int16_t>)
            return INT16;
        else if constexpr (std::is_same_v<std::decay_t<T>, int32_t>)
            return INT32;
        else if constexpr (std::is_same_v<std::decay_t<T>, int64_t>)
            return INT64;
        else if constexpr (std::is_same_v<std::decay_t<T>, uint8_t>)
            return UINT8;
        else if constexpr (std::is_same_v<std::decay_t<T>, uint16_t>)
            return UINT16;
        else if constexpr (std::is_same_v<std::decay_t<T>, uint32_t>)
            return UINT32;
        else if constexpr (std::is_same_v<std::decay_t<T>, uint64_t>)
            return UINT64;
        else
            return NONE;
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
    explicit operator T1() const
    {
        return isTypeInt8() ? static_cast<int16_t>(_value) : static_cast<T1>(_value);
    }

    template<isObjectIntAndNumber T1>
    constexpr Int& operator=(const T1& other)
    {
        _value = isObjectInt<T1> ? static_cast<T1>(other) : other;
        return *this;
    }

    template<isObjectIntAndNumber T1>
    constexpr Int& operator=(T1&& other) noexcept
    {
        _value = std::move(isObjectInt<T1> ? static_cast<T1>(other) : other);
        return *this;
    }

    constexpr Int& operator++()
    {
        ++_value;
        return *this;
    }
    constexpr Int operator++(int)
    {
        Int temp(*this);
        ++_value;
        return temp;
    }
    constexpr Int& operator--()
    {
        --_value;
        return *this;
    }
    constexpr Int operator--(int)
    {
        Int temp = *this;
        --_value;
        return temp;
    }

    template<isObjectIntAndNumber T1>
    [[nodiscard]] constexpr bool operator>(const T1& val) const
    {
        return _value > convertTypes(val);
    }

    template<isObjectIntAndNumber T1>
    [[nodiscard]] constexpr bool operator<(const T1& val) const
    {
        return _value < convertTypes(val);
    }

    template<isObjectIntAndNumber T1>
    [[nodiscard]] constexpr bool operator>=(const T1& val) const
    {
        return _value >= convertTypes(val);
    }

    template<isObjectIntAndNumber T1>
    [[nodiscard]] constexpr bool operator<=(const T1& val) const
    {
        return _value <= convertTypes(val);
    }

    template<isObjectIntAndNumber T1>
    [[nodiscard]] constexpr Int operator+(const T1& val) const
    {
        return Int(circumcisionOfValue(Int<int64_t>(_value + convertTypes(val))));
    }

    template<isObjectIntAndNumber T1>
    [[nodiscard]] constexpr Int operator-(const T1& val) const
    {
        return Int(circumcisionOfValue(Int<int64_t>(_value - convertTypes(val))));
    }

    template<isObjectIntAndNumber T1>
    [[nodiscard]] constexpr Int operator/(const T1& val) const
    {
        return static_cast<int8_t>(val)
            ? Int(circumcisionOfValue(Int<int64_t>(_value / convertTypes(val))))
            : Int{};
    }

    template<isObjectIntAndNumber T1>
    [[nodiscard]] constexpr Int operator*(const T1& val) const
    {
        return Int(circumcisionOfValue(Int<int64_t>(_value * convertTypes(val))));
    }

    template<isObjectIntAndNumber T1>
    constexpr Int& operator+=(const T1& val)
    {
        _value = circumcisionOfValue(Int<int64_t>(_value + convertTypes(val)));
        return *this;
    }

    template<isObjectIntAndNumber T1>
    constexpr Int& operator-=(const T1& val)
    {
        _value = circumcisionOfValue(Int<int64_t>(_value - convertTypes(val)));
        return *this;
    }

    template<isObjectIntAndNumber T1>
    constexpr Int& operator*=(const T1& val)
    {
        _value = circumcisionOfValue(Int<int64_t>(_value * convertTypes(val)));
        return *this;
    }

    template<isObjectIntAndNumber T1>
    constexpr Int& operator/=(const T1& val)
    {
        _value = static_cast<int8_t>(val) ? circumcisionOfValue(Int<int64_t>(_value / val))
                                          : convertTypes(val);
        return *this;
    }

    friend constexpr std::ostream& operator<<(std::ostream& os, const Int& other)
    {
        return os << (isTypeInt8() ? static_cast<int16_t>(convertTypes(other)) : convertTypes(other));
    }

    friend constexpr std::istream& operator>>(std::istream& os, Int& other)
    {
        return isTypeInt8() ? inputFromStream(os, reinterpret_cast<Int<int16_t>&>(other))
                            : ui(os, other);
    }

    [[nodiscard]] std::string convertToString() const
    {
        return std::to_string(_value);
    }

    template<isObjectInt T1>
    [[nodiscard]] static constexpr T1 convertToInt(const std::string& str)
    {
        if (str.empty())
            return T1{};

        switch (types())
        {
            case INT8:
            case INT16:
            case INT32: return T1(std::stoi(str));
            case INT64: return T1(std::stoll(str));
            case UINT8:
            case UINT16:
            case UINT32: return T1(std::stoul(str));
            case UINT64: return T1(std::stoull(str));
            default:     return T1{};
        }
    }

    [[nodiscard]] static constexpr Int<uint8_t> sizeValue()
    {
        return static_cast<Int<uint8_t>>(sizeof(T));
    }
    [[nodiscard]] static constexpr Int<uint8_t> size()
    {
        return static_cast<Int<uint8_t>>(sizeof(Int));
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
        switch (types())
        {
            case INT8: return "int8";
            case INT16: return "int16";
            case INT32: return "int32";
            case INT64: return "int64";

            case UINT8: return "uint8";
            case UINT16: return "uint16";
            case UINT32: return "uint32";
            case UINT64: return "uint64";

            default:  return std::string{};
        }
    }
};

using int32 = Int<int32_t>;
// using int16 = Int<int16_t>;
// using int8 = Int<int8_t>;
// using int64 = Int<int64_t>;
//
// using uint32 = Int<uint32_t>;
// using uint16 = Int<uint16_t>;
// using uint8 = Int<uint8_t>;
// using uint64 = Int<uint64_t>;


int main()
{
    int32 io{90};
    std::cout << io + 89;
    return 0;
}
