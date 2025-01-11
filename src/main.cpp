
#include <iostream>

#include "Types.hpp"

int main()
{
    constexpr int32 i32{32};

    constexpr float32 f32{90};
    const float64 f64{i32};
    constexpr float128 f128{8.8};

    std::cout << f32 << ' ' << f64 << ' ' << f128 << '\n';
    std::cout << (f32 >= f32) << '\n' << (f64 > 3) << '\n';
    std::cout << float32::max() << ' ' << float32::min() << '\n';
    std::cout << static_cast<long double>(pow(2, 32*16));

    return 0;
}
