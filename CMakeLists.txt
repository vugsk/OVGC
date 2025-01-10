cmake_minimum_required(VERSION 3.29)
project(ObjectStandartTypeCpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(ObjectStandartTypeCpp src/main.cpp
    src/TemplatesTypes/Int.hpp
    src/Types.hpp
#    src/TemplatesTypes/Char.cpp
#    src/TemplatesTypes/Char.hpp
    src/TemplatesTypes/Common.hpp
    src/TemplatesTypes/Float.cpp
    src/TemplatesTypes/Float.hpp
)
