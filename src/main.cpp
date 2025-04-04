
#include <iostream>

#include "BaseFunctionsObjects.hpp"
#include "Types.hpp"

int main()
{
    setlocale(LC_ALL, "");

    static constexpr auto FUNC = []<typename T, typename T1>(
        const types::Int<T>& val, T1 val2)
    {
        return val * val2;
    };

    std::cout << (int32{25} * 6) << '\n';

    int32 i32{25};
    int32 i16{6};

    std::cout << FUNC(i32, static_cast<int32_t>(6)) << '\n';

    //types::Pointer<int16> int_ptr{int32{45}};
    //std::cout << *int_ptr << std::endl;

    //types::Pointer<int16> i{12};

    //types::Pointer<int32> j{};

    //int32 ui{*j};

    //j = static_cast<types::Pointer<int32>>(i);
    // std::cout << *j << ' ' << (j == ui) << std::endl;

    // int32 i16{90};
    // float32 i8{0};
    // char8 ch{'A'};
    // bool1 bl{true};
    //
    // print(L"{} {} {} {}", i16, i8, ch, bl);

    // types::String<char8> string;
    //
    // auto ch8_ptr = new char8[2];
    // ch8_ptr[0] = 'l';
    // ch8_ptr[1] = '\0';
    // print("{}\n", ch8_ptr);
    // delete[] ch8_ptr;




    return 0;
}


