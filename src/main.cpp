
#include <iostream>

#include "BaseFunctionsObjects.hpp"
#include "Types.hpp"

int main()
{
    setlocale(LC_ALL, "");

    const char* str = "897";

    int32 i32_int(89);
    int32 i32_ch('s');
    int32 i32_str(str); // error

    std::cout << i32_int.getValue() << ' ' << i32_ch.getValue() << std::endl;

    return 0;
}


