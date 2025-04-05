//
// Created by nikita on 24.01.25.
//

#include <gtest/gtest.h>

#include "Types.hpp"

#include "AuxiliaryFunction.hpp"

TEST(TestTemplateIntType, TestTypeInt)
{
    EXPECT_EQ(int8::getType(), "int8");
    EXPECT_EQ(uint8::getType(), "uint8");

    EXPECT_EQ(int16::getType(), "int16");
    EXPECT_EQ(uint16::getType(), "uint16");

    EXPECT_EQ(int32::getType(), "int32");
    EXPECT_EQ(uint32::getType(), "uint32");

    EXPECT_EQ(int64::getType(), "int64");
    EXPECT_EQ(uint64::getType(), "uint64");
}

TEST(TestTemplateIntType, TestMinValueType)
{
    EXPECT_EQ(int8::min(), std::numeric_limits<int8_t>::min());
    EXPECT_EQ(uint8::min(), std::numeric_limits<uint8_t>::min());

    EXPECT_EQ(int16::min(), std::numeric_limits<int16_t>::min());
    EXPECT_EQ(uint16::min(), std::numeric_limits<uint16_t>::min());

    EXPECT_EQ(int32::min(), std::numeric_limits<int32_t>::min());
    EXPECT_EQ(uint32::min(), std::numeric_limits<uint32_t>::min());

    EXPECT_EQ(int64::min(), std::numeric_limits<int64_t>::min());
    EXPECT_EQ(uint64::min(), std::numeric_limits<uint64_t>::min());
}

TEST(TestTemplateIntType, TestMaxValueType)
{
    EXPECT_EQ(int8::max(), std::numeric_limits<int8_t>::max());
    EXPECT_EQ(uint8::max(), std::numeric_limits<uint8_t>::max());

    EXPECT_EQ(int16::max(), std::numeric_limits<int16_t>::max());
    EXPECT_EQ(uint16::max(), std::numeric_limits<uint16_t>::max());

    EXPECT_EQ(int32::max(), std::numeric_limits<int32_t>::max());
    EXPECT_EQ(uint32::max(), std::numeric_limits<uint32_t>::max());

    EXPECT_EQ(int64::max(), std::numeric_limits<int64_t>::max());
    EXPECT_EQ(uint64::max(), std::numeric_limits<uint64_t>::max());
}

TEST(TestTemplateIntType, TestMaxValueTypeS)
{
    EXPECT_EQ(int8::max().getType(), "int8");
    EXPECT_EQ(uint8::max().getType(), "uint8");

    EXPECT_EQ(int16::max().getType(), "int16");
    EXPECT_EQ(uint16::max().getType(), "uint16");

    EXPECT_EQ(int32::max().getType(), "int32");
    EXPECT_EQ(uint32::max().getType(), "uint32");

    EXPECT_EQ(int64::max().getType(), "int64");
    EXPECT_EQ(uint64::max().getType(), "uint64");
}

TEST(TestTemplateIntType, TestSizeObjectType)
{
    EXPECT_EQ(int8::size(), 1);
    EXPECT_EQ(uint8::size(), 1);

    EXPECT_EQ(int16::size(), 2);
    EXPECT_EQ(uint16::size(), 2);

    EXPECT_EQ(int32::size(), 4);
    EXPECT_EQ(uint32::size(), 4);

    EXPECT_EQ(int64::size(), 8);
    EXPECT_EQ(uint64::size(), 8);
}

TEST(TestTemplateIntType, TestSizeValueType)
{
    EXPECT_EQ(int8::sizeValue(), 1);
    EXPECT_EQ(uint8::sizeValue(), 1);

    EXPECT_EQ(int16::sizeValue(), 2);
    EXPECT_EQ(uint16::sizeValue(), 2);

    EXPECT_EQ(int32::sizeValue(), 4);
    EXPECT_EQ(uint32::sizeValue(), 4);

    EXPECT_EQ(int64::sizeValue(), 8);
    EXPECT_EQ(uint64::sizeValue(), 8);
}

TEST(TestTemplateIntType, TestConvertToString)
{
    static const std::string stringTestNumber = "25";

    EXPECT_EQ(i8.convertToString(), stringTestNumber);
    EXPECT_EQ(u8.convertToString(), stringTestNumber);

    EXPECT_EQ(i16.convertToString(), stringTestNumber);
    EXPECT_EQ(u16.convertToString(), stringTestNumber);

    EXPECT_EQ(i32.convertToString(), stringTestNumber);
    EXPECT_EQ(u32.convertToString(), stringTestNumber);

    EXPECT_EQ(i64.convertToString(), stringTestNumber);
    EXPECT_EQ(u64.convertToString(), stringTestNumber);
}

TEST(TestTemplateIntType, TestConvertToInt)
{
    static const std::string stringTestNumber = "78";
    static constexpr uint8 u8Tests{78};

    EXPECT_EQ(int8::convertToInt<int8>(stringTestNumber), u8Tests);
    EXPECT_EQ(uint8::convertToInt<uint8>(stringTestNumber), u8Tests);

    EXPECT_EQ(int16::convertToInt<int16>(stringTestNumber), u8Tests);
    EXPECT_EQ(uint16::convertToInt<uint16>(stringTestNumber), u8Tests);

    EXPECT_EQ(int32::convertToInt<int32>(stringTestNumber), u8Tests);
    EXPECT_EQ(uint32::convertToInt<uint32>(stringTestNumber), u8Tests);

    EXPECT_EQ(int64::convertToInt<int64>(stringTestNumber), u8Tests);
    EXPECT_EQ(uint64::convertToInt<uint64>(stringTestNumber), u8Tests);
}

TEST(TestTemplateIntType, TestOperatorOutput)
{
    static const std::string stringTestNumber = "25\n";

    EXPECT_EQ(testF(i8), stringTestNumber);
    EXPECT_EQ(testF(u8), stringTestNumber);

    EXPECT_EQ(testF(i16), stringTestNumber);
    EXPECT_EQ(testF(u16), stringTestNumber);

    EXPECT_EQ(testF(i32), stringTestNumber);
    EXPECT_EQ(testF(u32), stringTestNumber);

    EXPECT_EQ(testF(i64), stringTestNumber);
    EXPECT_EQ(testF(u64), stringTestNumber);
}


TEST(TestTemplateIntType, TestOperatorPlus)
{

    static constexpr auto FUNC = []<typename T, typename T1>(
        const types::Int<T>& val, T1 val2)
    {
        return val + val2;
    };

    ui(i8, FUNC, ARRAY_FOR_TESTS_PLUS);
    ui(u8, FUNC, ARRAY_FOR_TESTS_PLUS);
    ui(i16, FUNC, ARRAY_FOR_TESTS_PLUS);
    ui(u16, FUNC, ARRAY_FOR_TESTS_PLUS);
    ui(i32, FUNC, ARRAY_FOR_TESTS_PLUS);
    ui(u32, FUNC, ARRAY_FOR_TESTS_PLUS);
    ui(i64, FUNC, ARRAY_FOR_TESTS_PLUS);
    ui(u64, FUNC, ARRAY_FOR_TESTS_PLUS);

    ui2(i8, FUNC, ARRAY_TESTS_PLUS_);
    ui2(u8, FUNC, ARRAY_TESTS_PLUS_);
    ui2(i16, FUNC, ARRAY_TESTS_PLUS_);
    ui2(u16, FUNC, ARRAY_TESTS_PLUS_);
    ui2(i32, FUNC, ARRAY_TESTS_PLUS_);
    ui2(u32, FUNC, ARRAY_TESTS_PLUS_);
    ui2(i64, FUNC, ARRAY_TESTS_PLUS_);
    ui2(u64, FUNC, ARRAY_TESTS_PLUS_);

    EXPECT_EQ(i8 + 235, 127);
    EXPECT_EQ(i32 + -25, 0);
}

TEST(TestTemplateIntType, TestOperatorMinus)
{
    static constexpr auto FUNC = []<typename T, typename T1>(
        const types::Int<T>& val, T1 val2)
    {
        return val - val2;
    };

    ui(i8, FUNC, ARRAY_FOR_TESTS_MINUS);
    ui(u8, FUNC, ARRAY_FOR_TESTS_MINUS);
    ui(i16, FUNC, ARRAY_FOR_TESTS_MINUS);
    ui(u16, FUNC, ARRAY_FOR_TESTS_MINUS);
    ui(i32, FUNC, ARRAY_FOR_TESTS_MINUS);
    ui(u32, FUNC, ARRAY_FOR_TESTS_MINUS);
    ui(i64, FUNC, ARRAY_FOR_TESTS_MINUS);
    ui(u64, FUNC, ARRAY_FOR_TESTS_MINUS);

    ui2(i8, FUNC, ARRAY_TESTS_MINUS_);
    ui2(u8, FUNC, ARRAY_TESTS_MINUS_);
    ui2(i16, FUNC, ARRAY_TESTS_MINUS_);
    ui2(u16, FUNC, ARRAY_TESTS_MINUS_);
    ui2(i32, FUNC, ARRAY_TESTS_MINUS_);
    ui2(u32, FUNC, ARRAY_TESTS_MINUS_);
    ui2(i64, FUNC, ARRAY_TESTS_MINUS_);
    ui2(u64, FUNC, ARRAY_TESTS_MINUS_);

    EXPECT_EQ(i8 - 235, -128);
    EXPECT_EQ(i32 - -25, 50);
}

TEST(TestTemplateIntType, TestOperatorDis)
{
    static constexpr auto FUNC = []<typename T, typename T1>(
        const types::Int<T>& val, T1 val2)
    {
        return val / val2;
    };

    ui(i8, FUNC, ARRAY_FOR_TESTS_DIS);
    ui(u8, FUNC, ARRAY_FOR_TESTS_DIS);
    ui(i16, FUNC, ARRAY_FOR_TESTS_DIS);
    ui(u16, FUNC, ARRAY_FOR_TESTS_DIS);
    ui(i32, FUNC, ARRAY_FOR_TESTS_DIS);
    ui(u32, FUNC, ARRAY_FOR_TESTS_DIS);
    ui(i64, FUNC, ARRAY_FOR_TESTS_DIS);
    ui(u64, FUNC, ARRAY_FOR_TESTS_DIS);

    ui2(i8, FUNC, ARRAY_TESTS_DIS_);
    ui2(u8, FUNC, ARRAY_TESTS_DIS_);
    ui2(i16, FUNC, ARRAY_TESTS_DIS_);
    ui2(u16, FUNC, ARRAY_TESTS_DIS_);
    ui2(i32, FUNC, ARRAY_TESTS_DIS_);
    ui2(u32, FUNC, ARRAY_TESTS_DIS_);
    ui2(i64, FUNC, ARRAY_TESTS_DIS_);
    ui2(u64, FUNC, ARRAY_TESTS_DIS_);

}

// i32 -> int8 -> 127 – ???
TEST(TestTemplateIntType, TestOperatorMul)
{
    static constexpr auto FUNC = []<typename T, typename T1>(
        const types::Int<T>& val, T1 val2) -> types::Int<T>
    {
        return val * val2;
    };

    ui(i8, FUNC, ARRAY_FOR_TESTS_MUL);
    ui(u8, FUNC, ARRAY_FOR_TESTS_MUL);
    ui(i16, FUNC, ARRAY_FOR_TESTS_MUL);
    ui(u16, FUNC, ARRAY_FOR_TESTS_MUL);
    ui(i32, FUNC, ARRAY_FOR_TESTS_MUL);
    ui(u32, FUNC, ARRAY_FOR_TESTS_MUL);
    ui(i64, FUNC, ARRAY_FOR_TESTS_MUL);
    ui(u64, FUNC, ARRAY_FOR_TESTS_MUL);

    ui2(i8, FUNC, ARRAY_TESTS_MUL_);
    ui2(u8, FUNC, ARRAY_TESTS_MUL_);
    ui2(i16, FUNC, ARRAY_TESTS_MUL_);
    ui2(u16, FUNC, ARRAY_TESTS_MUL_);
    ui2(i32, FUNC, ARRAY_TESTS_MUL_);
    ui2(u32, FUNC, ARRAY_TESTS_MUL_);
    ui2(i64, FUNC, ARRAY_TESTS_MUL_);
    ui2(u64, FUNC, ARRAY_TESTS_MUL_);
}

TEST(TestTemplateIntType, TestOperatorEqual)
{

}

TEST(TestTemplateIntType, TestOperatorNotEqual)
{

}

TEST(TestTemplateIntType, TestOperatorBig)
{

}

TEST(TestTemplateIntType, TestOperatorSmall)
{

}

TEST(TestTemplateIntType, TestOperatorBigOrEqual)
{

}

TEST(TestTemplateIntType, TestOperatorSmallOrEqual)
{

}

TEST(TestTemplateIntType, TestOperatorDoublePlusFront)
{

}

TEST(TestTemplateIntType, TestOperatorDoublePlusBack)
{

}

TEST(TestTemplateIntType, TestOperatorDoubleMinusFront)
{

}

TEST(TestTemplateIntType, TestOperatorDoubleMinusBack)
{

}

TEST(TestTemplateIntType, TestOperatorPlusAssing)
{

}

TEST(TestTemplateIntType, TestOperatorMulAssing)
{

}

TEST(TestTemplateIntType, TestOperatorDisAssing)
{

}

TEST(TestTemplateIntType, TestOperatorMinusAssing)
{

}

TEST(TestTemplateIntType, TestConvertType)
{

}

TEST(TestTemplateIntType, TestConstructe)
{

}
