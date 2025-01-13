cmake_minimum_required(VERSION 3.29)
project(ObjectStandartTypeCpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(ObjectStandartTypeCpp src/main.cpp
    src/TemplatesTypes/Int.hpp
    src/Types.hpp
    src/TemplatesTypes/Char.hpp
    src/TemplatesTypes/Common.hpp
    src/TemplatesTypes/Float.hpp
    src/TemplatesTypes/Bool.hpp
    src/TemplatesTypes/String.hpp
    src/BaseFunctions/Print.hpp
    src/BaseFunctionsObjects.hpp
    src/CustomFunctionsFromStandartLibrary/CustomFormat.hpp
)
