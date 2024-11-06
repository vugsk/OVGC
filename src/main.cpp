
#include <iostream>

#include "Types.hpp"


int main()
{

    int32 i32{32};

    float32 f32{90};
    float64 f64{i32};
    float128 f128{8.8};

    std::cout << f32 << ' ' << f64 << ' ' << f128 << '\n';
    std::cout << std::numeric_limits<long double>::max() << '\n';
    std::cout << static_cast<long double>(pow(2, 32*4*16));

    return 0;
}
