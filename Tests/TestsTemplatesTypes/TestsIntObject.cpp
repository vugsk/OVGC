//
// Created by nikita on 24.01.25.
//

#include <gtest/gtest.h>

#include "Types.hpp"

static constexpr int8 i8{25};
static constexpr uint8 u8{25};
static constexpr int16 i16{25};
static constexpr uint16 u16{25};
static constexpr int32 i32{25};
static constexpr uint32 u32{25};
static constexpr int64 i64{25};
static constexpr uint64 u64{25};

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


