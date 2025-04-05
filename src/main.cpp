
#include <iostream>

#include "BaseFunctionsObjects.hpp"
#include "Types.hpp"

int main()
{
    setlocale(LC_ALL, "");

    const char* str = "897";

    int32 i32_int(89);
    int32 i32_ch('9');
    int32 i32_str(str);

    std::cout << i32_int.getValue() << ' '
              << i32_ch.getValue() << ' '
              << i32_str.getValue() << std::endl;

    return 0;
}


