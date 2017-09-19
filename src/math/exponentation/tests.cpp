#include "main.cpp"
#include <gtest/gtest.h>

TEST(exponentTest, PositiveNumbers) { 
    ASSERT_EQ(8, exponent(2, 3));
    ASSERT_EQ(6.25, exponent(2.5, 2));
    ASSERT_EQ(3.9, exponent(3.9, 1));
}

TEST(exponentTest, ZeroNumbers) {
    ASSERT_DEATH(exponent(0.0, 0);, "incorrect math operation");
    ASSERT_DEATH(exponent(0, 0);, "incorrect math operation");
    ASSERT_EQ(1, exponent(5.3, 0));
    ASSERT_EQ(0, exponent(0, 5));
}
 
TEST(exponentTest, NegativeNumbers) {
    ASSERT_DEATH(exponent(5, -5);, "power of exponent should be non-negative int number");
    ASSERT_EQ(1, exponent(-1, 2));
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
