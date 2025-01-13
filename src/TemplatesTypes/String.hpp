//
// Created by nikita on 13.01.25.
//

#ifndef STRING_HPP
#define STRING_HPP
#include "Common.hpp"
#include "Int.hpp"


namespace types
{

template<concepts::isObjectChar C>
class String
{
private:
    std::unique_ptr<C[]> str;
    Int<uint64_t> size;


public:
    constexpr String() {}
    constexpr String(const std::string& str)
    {

    }
    constexpr String(std::string&& str)
    {

    }
    constexpr String(const char* const& str)
    {

    }
    constexpr String(C value)
    {

    }
    constexpr String(const String& str) {}
    constexpr String(String&& str) {}
    ~String() {}



};


}

#endif //STRING_HPP
