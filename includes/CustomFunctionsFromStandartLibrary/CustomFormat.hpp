//
// Created by nikita on 13.01.25.
//

#ifndef CUSTOMFORMAT_HPP
#define CUSTOMFORMAT_HPP

#include <format>

#include "../TemplatesTypes/Char.hpp"
#include "../TemplatesTypes/Float.hpp"
#include "../TemplatesTypes/Int.hpp"
#include "../TemplatesTypes/String.hpp"


namespace std
{

// type int
// template <typename T, typename T_C>
// struct formatter<types::Int<T>, T_C>
// {
//     // Парсинг спецификации формата (например, "{:d}" или "{:x}")
//     constexpr auto parse(basic_format_parse_context<T_C>& ctx)
//     {
//         return ctx.begin(); // Пока просто пропускаем спецификацию
//     }
//
//     // Форматирование значения
//     auto format(const types::Int<T>& value, __format::__format_context<T_C>& ctx) const
//     {
//         // Используем стандартный форматтер для int
//         return format_to(ctx.out(), "{}", static_cast<T>(value));
//     }
// };
//
// // type float
// template <typename T, typename T_C>
// struct formatter<types::Float<T>, T_C>
// {
//     // Парсинг спецификации формата (например, "{:d}" или "{:x}")
//     constexpr auto parse(basic_format_parse_context<T_C>& ctx)
//     {
//         return ctx.begin(); // Пока просто пропускаем спецификацию
//     }
//
//     // Форматирование значения
//     auto format(const types::Float<T>& value, __format::__format_context<T_C>&
//     ctx) const
//     {
//         // Используем стандартный форматтер для int
//         return format_to(ctx.out(), "{}", static_cast<T>(value));
//     }
// };
//
// // type char
// template <typename T, typename T_C>
// struct formatter<types::Char<T>, T_C>
// {
//     // Парсинг спецификации формата (например, "{:d}" или "{:x}")
//     constexpr auto parse(basic_format_parse_context<T_C>& ctx)
//     {
//         return ctx.begin(); // Пока просто пропускаем спецификацию
//     }
//
//     // Форматирование значения
//     auto format(const types::Char<T>& value, __format::__format_context<T_C>& ctx) const
//     {
//         // Используем стандартный форматтер для int
//         return format_to(ctx.out(), "{}", static_cast<T>(value));
//     }
// };

// types pointer
// fix
// template <typename T, typename T_C>
// struct formatter<types::Char<T>*, T_C>
// {
//     // Парсинг спецификации формата (например, "{:d}" или "{:x}")
//     constexpr auto parse(basic_format_parse_context<T_C>& ctx)
//     {
//         return ctx.begin(); // Пока просто пропускаем спецификацию
//     }
//
//     // Форматирование значения
//     auto format(const types::Char<T>* const& value,
//         __format::__format_context<T_C>& ctx) const
//     {
//         // Используем стандартный форматтер для int
//
//         return format_to(ctx.out(), "{}", );
//     }
// };

// type Bool
// template<typename T_C>
// struct formatter<types::Bool, T_C>
// {
//     // Парсинг спецификации формата (например, "{:d}" или "{:x}")
//     constexpr auto parse(basic_format_parse_context<T_C>& ctx)
//     {
//         return ctx.begin(); // Пока просто пропускаем спецификацию
//     }
//
//     // Форматирование значения
//     auto format(const types::Bool& value, __format::__format_context<T_C>& ctx) const
//     {
//         // Используем стандартный форматтер для int
//         return format_to(ctx.out(), "{}", static_cast<bool>(value));
//     }
// };

// types string
// template <typename T, typename T_C>
// struct formatter<types::String<types::Char<T>>, T_C>
// {
//     // Парсинг спецификации формата (например, "{:d}" или "{:x}")
//     constexpr auto parse(basic_format_parse_context<T_C>& ctx)
//     {
//         return ctx.begin(); // Пока просто пропускаем спецификацию
//     }
//
//     // Форматирование значения
//     auto format(const types::String<types::Char<T>>& value, __format::__format_context<T_C>& ctx) const
//     {
//         // Используем стандартный форматтер для int
//         return format_to(ctx.out(), "{}", value.getValue());
//     }
// };

}

#endif //CUSTOMFORMAT_HPP
