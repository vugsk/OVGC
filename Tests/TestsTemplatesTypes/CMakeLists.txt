cmake_minimum_required(VERSION 3.29)

set(NAME_PROJECT_T TemplatesTypes)

project(${NAME_PROJECT_T})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADER_FILES_T
    AuxiliaryFunction.hpp
)

set(SOURCE_FILES_T
    TestsIntObject.cpp
)

enable_testing()

add_executable(${NAME_PROJECT_T}
    ${SOURCE_FILES_T}
    ${HEADER_FILES_T}
)
target_link_libraries(${NAME_PROJECT_T} gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(${NAME_PROJECT_T})

