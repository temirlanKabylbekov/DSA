#include "main.cpp"
#include <gtest/gtest.h>


/*PUSH TESTS*/
TEST(TestStack, testPushToEmptyStack) {
    CStack stack(10);
    stack.push(11);
    ASSERT_EQ(stack.peek(), 11);
}

TEST(TestStack, testPushToOversizingStack) {
    CStack stack(1);
    stack.push(11);
    ASSERT_EQ(stack.peek(), 11);
}

TEST(TestStack, testPushToOversizedStack) {
    CStack stack(2);
    stack.push(11);
    stack.push(22);
    ASSERT_DEATH(stack.push(33);, "the size of buffer reached maximum");
}

/*POP TESTS*/
TEST(TestStack, testPopFromEmptyStack) {
    CStack stack(2);
    ASSERT_DEATH(stack.pop();, "stack is empty");
}

TEST(TestStack, testPopFromOversizedStack) {
    CStack stack(2);
    stack.push(11);
    stack.push(22);
    ASSERT_EQ(stack.pop(), 22);
}

TEST(TestStack, testPopFromStack) {
    CStack stack(3);
    stack.push(11);
    stack.push(22);
    ASSERT_EQ(stack.pop(), 22);
}

/*PEEK TESTS*/
TEST(TestStack, testPeekFromEmptyStack) {
    CStack stack(2);
    ASSERT_DEATH(stack.peek();, "stack is empty");
}

TEST(TestStack, testPeekFromOversizedStack) {
    CStack stack(2);
    stack.push(11);
    stack.push(22);
    ASSERT_EQ(stack.peek(), 22);
}

TEST(TestStack, testPeekFromStack) {
    CStack stack(3);
    stack.push(11);
    stack.push(22);
    ASSERT_EQ(stack.peek(), 22);
}

/*GET SIZE TESTS*/
TEST(TestStack, testGetSizeFromEmptyStack) {
    CStack stack(2);
    ASSERT_EQ(stack.getSize(), 0);
}

TEST(TestStack, testGetSizeFromOversizedStack) {
    CStack stack(2);
    stack.push(11);
    stack.push(22);
    ASSERT_EQ(stack.getSize(), 2);
}

TEST(TestStack, testGetSizeFromStack) {
    CStack stack(3);
    stack.push(11);
    stack.push(22);
    ASSERT_EQ(stack.getSize(), 2);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}