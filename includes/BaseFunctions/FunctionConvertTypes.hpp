//
// Created by ganch on 05.04.2025.
//

#ifndef FUNCTIONCONVERTTYPES_HPP
#define FUNCTIONCONVERTTYPES_HPP

#include "CustomException/ExceptionCheckTypes/ExceptionTypes.hpp"

namespace base_functions
{

template<typename ReturnTypeInteger>
ReturnTypeInteger ConvertCharToInteger(const char char_number)
{
    if (!isdigit(char_number))
        throw exception_types::ExceptionTypes("Error: not char number");
    return static_cast<ReturnTypeInteger>(char_number - '0');
}

template<typename ReturnTypeInteger>
ReturnTypeInteger ConvertStringToInteger(const char* str_number)
{

}

}


#endif //FUNCTIONCONVERTTYPES_HPP
