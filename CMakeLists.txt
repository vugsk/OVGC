cmake_minimum_required(VERSION 3.29)

set(NAME_PROJECT ObjectStandartTypeCpp)
set(NAME_PROJECT_LIB ${NAME_PROJECT}_lib)

project(${NAME_PROJECT})

set(CMAKE_CXX_STANDARD 20)

set(HEADER_FILES
    includes/TemplatesTypes/Int.hpp
    includes/Types.hpp
    includes/TemplatesTypes/Char.hpp
    includes/TemplatesTypes/Common.hpp
    includes/TemplatesTypes/Float.hpp
    includes/TemplatesTypes/Bool.hpp
    includes/TemplatesTypes/String.hpp
    includes/BaseFunctions/Print.hpp
    include/BaseFunctions/FunctionConvertTypes.hpp
    includes/BaseFunctionsObjects.hpp
    includes/CustomFunctionsFromStandartLibrary/CustomFormat.hpp
    includes/TemplatesTypes/Pointer.hpp
    includes/CustomException/ExceptionCheckTypes/ExceptionTypes.hpp
)

include_directories(includes/)

option(TEST_BUILD "Build program with tests?" OFF)
message("Build tests - " ${TEST_BUILD})
if (${TEST_BUILD})
    message("OK, tests")
    add_subdirectory(Tests)
else()
    message("No, tests")
    
    option(BUILD_EXP "" OFF)
    if(${BUILD_EXP})
        # ???
    else()
        add_executable(${NAME_PROJECT} src/main.cpp)
    endif()
    target_include_directories(${NAME_PROJECT} PUBLIC ${HEADER_FILES})
endif()

