/**
 * @file bigint_test.cpp
 * @author Purbayan Chowdhury (pur.cho.99@gmail.com)
 * @brief Unit Test for BigInt
 * @version 0.1
 * @date 2022-02-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <gtest/gtest.h>
#include "../src/bigint.hpp"

class bigint_test : public ::testing::Test
{
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }
};

TEST_F(bigint_test, bigint_to_string)
{
    bigint b1("4172"), b2("78931"), b3("-94231"), b4("-0");
    EXPECT_EQ(b1.to_string(), "4172");
    EXPECT_EQ(b2.to_string(), "78931");
    EXPECT_EQ(b3.to_string(), "-94231");
    EXPECT_EQ(b3.to_string(), "-94231");
    EXPECT_EQ(b4.to_string(), "0");
}