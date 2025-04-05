//
// Created by ganch on 04.11.2024.
//

#ifndef TYPES_HPP
#define TYPES_HPP

// #include "TemplatesTypes/Bool.hpp"
// #include "TemplatesTypes/Char.hpp"
// #include "TemplatesTypes/Float.hpp"
#include "TemplatesTypes/Int.hpp"

// #include "TemplatesTypes/Pointer.hpp"


using int32 = types::Int<int32_t>;
using int16 = types::Int<int16_t>;
using int8  = types::Int<int8_t>;
using int64 = types::Int<int64_t>;

using uint32 = types::Int<uint32_t>;
using uint16 = types::Int<uint16_t>;
using uint8 = types::Int<uint8_t>;
using uint64 = types::Int<uint64_t>;

// using float32 = types::Float<float>;
// using float64 = types::Float<double>;
// using float128 = types::Float<long double>;
//
// using bool1 = types::Bool;
//
// using char8 = types::Char<char8_t>;
// using char16 = types::Char<char16_t>;
// using char32 = types::Char<char32_t>;


// Pointer types

// using char8_ptr = types::Pointer<types::Char<char8_t>>;
// using char16_ptr = types::Pointer<types::Char<char16_t>>;
// using char32_ptr = types::Pointer<types::Char<char32_t>>;
//
// using bool1_ptr = types::Pointer<types::Bool>;
//
// using int8_ptr = types::Pointer<types::Int<int8_t>>;
// using int16_ptr = types::Pointer<types::Int<int16_t>>;
// using int32_ptr = types::Pointer<types::Int<int32_t>>;
// using int64_ptr = types::Pointer<types::Int<int64_t>>;
//
// using uint8_ptr = types::Pointer<types::Int<uint8_t>>;
// using uint32_ptr = types::Pointer<types::Int<uint32_t>>;
// using uint16_ptr = types::Pointer<types::Int<uint16_t>>;
// using uint64_ptr = types::Pointer<types::Int<uint64_t>>;
//
// using float32_ptr = types::Pointer<types::Float<float>>;
// using float64_ptr = types::Pointer<types::Float<double>>;
// using float128_ptr = types::Pointer<types::Float<long double>>;

#endif //TYPES_HPP
