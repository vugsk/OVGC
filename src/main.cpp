
#include <iostream>

#include "Types.hpp"

int main()
{
    setlocale(LC_ALL, "");

    static constexpr int32 i32{89};
    static constexpr float32 f32{90};

    char8 c8(i32);
    char16 c16(f32);
    char32 c32(L'р');
    char16 ch16(L'л');
    c8 = ch16;
    std::wcout << ch16 << c32 << std::endl;

    // std::cout << static_cast<long double>(pow(2, 32*16));

    return 0;
}


