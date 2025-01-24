//
// Created by nikita on 18.01.25.
//

#ifndef POINTER_HPP
#define POINTER_HPP

#include <memory>

namespace types
{

template<typename ObjectTypes>
class Pointer
{
private:
    std::shared_ptr<ObjectTypes> _value;

public:
    using type = ObjectTypes;
    using typePointer = std::shared_ptr<ObjectTypes>;
    using typeObject = Pointer<ObjectTypes>;

    constexpr Pointer() noexcept : _value(nullptr) {}

    template<concepts::isObjectTypes ObjectType>
    explicit Pointer(ObjectType&& value)
        : _value(std::make_shared<ObjectTypes>(
            std::move(static_cast<ObjectTypes>(value)))) {}

    template<concepts::isObjectTypes ObjectType>
    explicit Pointer(const ObjectType& value)
        : _value(std::make_shared<ObjectTypes>(value)) {}

    template<concepts::isObjectTypes ObjectType>
    explicit Pointer(std::unique_ptr<ObjectType>&& ptr)
        : _value(std::move(ptr)) {}

    template<concepts::isObjectTypes ObjectType>
    explicit Pointer(std::shared_ptr<ObjectType>&& ptr)
        : Pointer(static_cast<ObjectType>(*std::move(ptr))) {}

    template<concepts::isObjectType ObjectType>
    [[nodiscard]] Pointer& operator=(const Pointer<ObjectType>& other)
    {
        if (this == &other)
            return *this;
        _value = other._value;
        return *this;
    }

    template<concepts::isObjectType ObjectType>
    [[nodiscard]] Pointer& operator=(Pointer<ObjectType>&& other) noexcept
    {
        if (this == &other)
            return *this;
        _value = std::move(other._value);
        other._value = ObjectType{};
        return *this;
    }

    template<typename TypePointer> requires std::is_pointer_v<TypePointer>
    [[nodiscard]] explicit operator TypePointer() const
    {
        return new std::remove_pointer_t<TypePointer>(*_value);
    }

    template<concepts::isObjectTypes T>
    [[nodiscard]] explicit operator std::shared_ptr<T>() const
    {
        return std::make_shared<T>(static_cast<T>(*_value));
    }

    template<concepts::isObjectTypes T>
    [[nodiscard]] explicit operator std::unique_ptr<T>() const
    {
        return std::make_unique<T>(static_cast<T>(*_value));
    }

    template<concepts::isObjectTypes T>
    [[nodiscard]] explicit operator Pointer<T>() const
    {
        return Pointer<T>(*_value);
    }

    [[nodiscard]] ObjectTypes operator*() const
    {
        if (_value)
            return *_value;
        return ObjectTypes{};
    }

    [[nodiscard]] ObjectTypes* operator->() const
    {
        if (_value)
            return _value.get();
        return nullptr;
    }

    [[nodiscard]] ObjectTypes* operator&() const
    {
        if (_value)
            return _value.get();
        return nullptr;
    }

    [[nodiscard]] constexpr Bool isNull() const
    {
        return _value == nullptr;
    }

    // template<typename ObjectType> // requires concepts::isObjectTypes<ObjectType> ||
    //     // std::is_same_v<ObjectType, Pointer<typename ObjectType::value_type>>
    // [[nodiscard]] constexpr bool operator==(const ObjectType& val) const
    // {
    //     if constexpr (std::is_same_v<ObjectType, ObjectTypes>)
    //     {
    //         return *_value == val;
    //     }
    //     else
    //     {
    //         return false;
    //     }
    // }

    // template<typename ObjectType> requires concepts::isObjectTypes<ObjectType> ||
    //     std::is_same_v<ObjectType, Pointer<typename ObjectType::value_type>>
    // constexpr Bool operator>=(const ObjectType& val) const
    // {
    //     if constexpr (std::is_same_v<ObjectType, Pointer<typename ObjectType::value_type>>)
    //         return *_value >= *val;
    //     else
    //         return _value >= static_cast<ObjectTypes>(val);
    // }
    // constexpr Bool operator<=() {}
    // constexpr Bool operator!=() {}
    // constexpr Bool operator>() {}
    // constexpr Bool operator<() {}
};

}


#endif //POINTER_HPP
