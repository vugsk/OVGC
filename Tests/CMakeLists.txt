cmake_minimum_required(VERSION 3.29)
project(TestsObjectStandartType)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

option(TESTS_TEMPLATES_TYPES "" OFF)
if (${TESTS_TEMPLATES_TYPES})
    add_subdirectory(TestsTemplatesTypes)
endif()

#option(TESTS_TEMPLATES_TYPES "" OFF)
#if (${TESTS_TEMPLATES_TYPES})
#    add_subdirectory(TestsTemplatesTypes)
#endif()
#
#option(TESTS_TEMPLATES_TYPES "" OFF)
#if (${TESTS_TEMPLATES_TYPES})
#    add_subdirectory(TestsTemplatesTypes)
#endif()
#
#option(TESTS_TEMPLATES_TYPES "" OFF)
#if (${TESTS_TEMPLATES_TYPES})
#    add_subdirectory(TestsTemplatesTypes)
#endif()

