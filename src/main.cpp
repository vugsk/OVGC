
#include <iostream>

#include "Types.hpp"

int main()
{
    constexpr int32 i32{32};

    float32 f32{90};
    float64 f64{i32};
    float128 f128{8.8};

    f32 /= i32;
    std::cout << f32 + f64 << std::endl;

    // std::cout << static_cast<long double>(pow(2, 32*16));

    return 0;
}


