//
// Created by nikita on 13.01.25.
//

#ifndef PRINT_HPP
#define PRINT_HPP

#include <format>

namespace base_functions
{

class Print
{
public:
    template <typename... Args>
    void operator()(const std::wstring_view& format, Args&&... args) const
    {
        std::wcout << std::vformat(format, std::make_wformat_args(args...)) << '\n';
    }

    template <typename... Args>
    void operator()(const std::string_view& format, Args&&... args) const
    {
        std::cout << std::vformat(format, std::make_format_args(args...)) << '\n';
    }
};

}

#endif //PRINT_HPP
