//
// Created by ganch on 05.04.2025.
//

#ifndef FUNCTIONCONVERTTYPES_HPP
#define FUNCTIONCONVERTTYPES_HPP

#ifdef DEBUG_BASE_FUNCTION
    #include <iostream>
#endif

#include "RestrictionsForTemplates/RestrictionsForTypes.hpp"
#include "CustomException/ExceptionCheckTypes/ExceptionTypes.hpp"

namespace base_functions
{



template<typename ReturnTypeInteger>
constexpr ReturnTypeInteger ConvertCharToInteger(const char char_number)
{
    if (char_number < '0' || char_number > '9')
        throw exception_types::ExceptionTypes("Error: not char number");
    return static_cast<ReturnTypeInteger>(char_number - '0');
}

template<typename ReturnTypeInteger>
constexpr ReturnTypeInteger ConvertStringToInteger(const char* str_number)
{
    // if constexpr
}

}


#endif //FUNCTIONCONVERTTYPES_HPP
