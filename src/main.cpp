
#include <iostream>

#include "BaseFunctionsObjects.hpp"
#include "Types.hpp"


int main()
{
    setlocale(LC_ALL, "");

    int32 i16{90};
    float32 i8{0};
    char8 ch{'A'};
    bool1 bl{true};


    print(L"{} {} {} {}", i16, i8, ch, bl);

    return 0;
}


