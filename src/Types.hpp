//
// Created by ganch on 04.11.2024.
//

#ifndef TYPES_HPP
#define TYPES_HPP

// #include "TemplatesTypes/Char.hpp"
#include "TemplatesTypes/Float.hpp"
#include "TemplatesTypes/Int.hpp"

using int32 = types::Int<int32_t>;
using int16 = types::Int<int16_t>;
using int8  = types::Int<int8_t>;
using int64 = types::Int<int64_t>;

using uint32 = types::Int<uint32_t>;
using uint16 = types::Int<uint16_t>;
using uint8 = types::Int<uint8_t>;
using uint64 = types::Int<uint64_t>;

using float32 = types::Float<float>;
using float64 = types::Float<double>;
using float128 = types::Float<long double>;

// using char8 = types::Char<char8_t>;
// using char16 = types::Char<char16_t>;
// using char32 = types::Char<char32_t>;

#endif //TYPES_HPP
