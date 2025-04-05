//
// Created by ganch on 05.04.2025.
//

#ifndef EXCEPTIONTYPES_HPP
#define EXCEPTIONTYPES_HPP

#include <exception>

namespace exception_types
{

class ExceptionTypes : public std::exception
{
private:
    const char* _msg;

public:
    explicit ExceptionTypes(const char* const& msg)
        : _msg(std::move(msg)) {}
    ~ExceptionTypes() noexcept override = default;
    const char* what() const noexcept override
    {
        return _msg;
    }
};

}

#endif //EXCEPTIONTYPES_HPP
