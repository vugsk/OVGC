//
// Created by nikita on 13.01.25.
//

#ifndef STRING_HPP
#define STRING_HPP

#include "Char.hpp"
#include "Common.hpp"
#include "Int.hpp"


namespace types
{

// template<concepts::isObjectChar C>
class String
{
// private:
//     std::unique_ptr<C[]> _str;
//     Int<uint64_t> _size;
//
//     static constexpr Char<char8_t> END_SYBOLE{'\0'};
//
//
// public:
//     constexpr String()
//     {
//         _str = std::make_unique<C[]>(1);
//         _size = 0;
//         _str[0] = static_cast<C>(END_SYBOLE);
//     }
//     constexpr String(const std::string& str)
//     {
//         _size = str.size();
//         for (const auto& c : str)
//         {
//
//         }
//     }
//     constexpr String(std::string&& str)
//     {
//
//     }
//     constexpr String(const char* const& str)
//     {
//
//     }
//     constexpr String(C value)
//     {
//
//     }
//     constexpr String(const String& str) {}
//     constexpr String(String&& str) noexcept {}
//     ~String() = default;
//
//     constexpr C* getValue() const
//     {
//         return _str.get();
//     }
//
//     template<concepts::isObjectChar Ch>
//     void push(Ch ch)
//     {
//         std::unique_ptr<C[]> temp = std::make_unique<C[]>(_size + 1);
//         for (Int<uint64_t> i; i < _size; ++i)
//             temp[i] = _str[i];
//         _str = nullptr;
//         ++_size;
//         temp[_size] = ch;
//         temp[_size + 1] = END_SYBOLE;
//         _str = std::move(temp);
//         temp = nullptr;
//     }

};


}

#endif //STRING_HPP
