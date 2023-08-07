#include <gtest/gtest.h>
#include "metatemplate_algorithms/cute/utility.hpp"

// Test for ceil function
TEST(CeilingTest, BasicCases)
{
    EXPECT_EQ(cute::ceil(5), 5);
    EXPECT_EQ(cute::ceil(5.1), 6);
    EXPECT_EQ(cute::ceil(-5), -5);
    EXPECT_EQ(cute::ceil(-5.1), -5);
}

// Test for floor function
TEST(FloorTest, BasicCases)
{
    EXPECT_EQ(cute::floor(5), 5);
    EXPECT_EQ(cute::floor(5.1), 5);
    EXPECT_EQ(cute::floor(-5), -5);
    EXPECT_EQ(cute::floor(-5.1), -6);
}

// Test for genericAssign function
TEST(GenericAssignTest, BasicCases)
{
    int x = 10;
    int y = 20;

    cute::genericAssign(x, y);
    EXPECT_EQ(x, 20); // x should be assigned the value of y

    int z = 30;
    cute::genericAssign(x, z);
    EXPECT_EQ(x, 30); // x should be assigned the value of z

    // For types that have an assignment operator, the genericAssign should not be used
    std::string str1 = "Hello";
    std::string str2 = "World";
    // cute::genericAssign(str1, str2); // This should not compile

    // Add more test cases for different types if needed
}

