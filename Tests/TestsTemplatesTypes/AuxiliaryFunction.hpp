//
// Created by nikita on 25.01.25.
//

#ifndef AUXILIARYFUNCTION_HPP
#define AUXILIARYFUNCTION_HPP

static constexpr int8 i8{25};
static constexpr uint8 u8{25};

static constexpr int16 i16{25};
static constexpr uint16 u16{25};

static constexpr int32 i32{25};
static constexpr uint32 u32{25};

static constexpr int64 i64{25};
static constexpr uint64 u64{25};

static constexpr uint8_t uint8Tests = 1;
static constexpr int8_t int8Tests = 2;

static constexpr uint16_t uint16Tests = 1;
static constexpr int16_t int16Tests = 1;

static constexpr uint32_t uint32Tests = 1;
static constexpr int32_t int32Tests = 6;

static constexpr uint64_t uint64Tests = 8;
static constexpr int64_t int64Tests = 3;


template<typename T>
static std::string testF(const types::Int<T>& num)
{
    std::streambuf* old = std::cout.rdbuf();
    const std::stringstream capturedString;
    std::cout.rdbuf(capturedString.rdbuf());
    std::cout << num << std::endl;
    std::cout.rdbuf(old);
    return capturedString.str();
}

static constexpr std::array ARRAY_FOR_TESTS_PLUS{27, 26, 26, 26, 31, 26, 28, 33};
static constexpr std::array ARRAY_TESTS_PLUS_{50, 50, 50, 50, 50, 50, 50, 50};

static constexpr std::array ARRAY_FOR_TESTS_MINUS{23, 24, 24, 24, 19, 24, 22, 17};
static constexpr std::array ARRAY_TESTS_MINUS_{0, 0, 0, 0, 0, 0, 0, 0};

static constexpr std::array ARRAY_FOR_TESTS_DIS{12, 25, 25, 25, 4, 25, 8, 3};
static constexpr std::array ARRAY_TESTS_DIS_{1, 1, 1, 1, 1, 1, 1, 1};

// rewrite
static constexpr std::array ARRAY_FOR_TESTS_MUL{50, 25, 25, 25, 150, 25, 75, 200};
static constexpr std::array ARRAY_TESTS_MUL_{225, 225, 225, 225, 225, 225, 225, 225};


template<typename T, typename F>
static constexpr void ui(const types::Int<T>& num, F&& func,
    const std::array<int, 8>& arr)
{

    std::cout << "jd " << num.getType() << ' ' << num << ' ' << num * 6 << ' ' << func(num, int32Tests) << std::endl;

    EXPECT_EQ(func(num, int8Tests), arr[0]);
    EXPECT_EQ(func(num, uint8Tests), arr[1]);
    EXPECT_EQ(func(num, int16Tests), arr[2]);
    EXPECT_EQ(func(num, uint16Tests), arr[3]);
    EXPECT_EQ(func(num, int32Tests), arr[4]);
    EXPECT_EQ(func(num, uint32Tests), arr[5]);
    EXPECT_EQ(func(num, int64Tests), arr[6]);
    EXPECT_EQ(func(num, uint64Tests), arr[7]);
}

template<typename T, typename F>
static constexpr void ui2(const types::Int<T>& num, F&& func,
    const std::array<int, 8>& arr)
{
    EXPECT_EQ(func(num, i8), arr[0]);
    EXPECT_EQ(func(num, u8), arr[1]);
    EXPECT_EQ(func(num, i16), arr[2]);
    EXPECT_EQ(func(num, u16), arr[3]);
    EXPECT_EQ(func(num, i32), arr[4]);
    EXPECT_EQ(func(num, u32), arr[5]);
    EXPECT_EQ(func(num, i64), arr[6]);
    EXPECT_EQ(func(num, u64), arr[7]);
}

#endif //AUXILIARYFUNCTION_HPP
