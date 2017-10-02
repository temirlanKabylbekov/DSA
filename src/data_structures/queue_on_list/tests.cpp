#include "main.cpp"
#include <gtest/gtest.h>


TEST(TestQueue, testEnqueueToEmptyQueue) {
    CQueue queue;
    queue.enqueue(11);
    ASSERT_EQ(queue.dequeue(), 11);
}

TEST(TestQueue, testDequeueFromEmptyQueue) {
    CQueue queue;
    ASSERT_DEATH(queue.dequeue();, "queue is empty");
}

TEST(TestQueue, testEnqueueAndDequeueTillEmpty) {
    CQueue queue;
    queue.enqueue(11);
    queue.enqueue(22);
    queue.enqueue(33);
    queue.enqueue(44);

    ASSERT_EQ(queue.dequeue(), 11);
    ASSERT_EQ(queue.dequeue(), 22);
    ASSERT_EQ(queue.dequeue(), 33);
    ASSERT_EQ(queue.dequeue(), 44);
    ASSERT_DEATH(queue.dequeue();, "queue is empty");
}

TEST(TestQueue, testgetSizeFromEmptyQueue) {
    CQueue queue;
    ASSERT_EQ(queue.getSize(), 0);
}

TEST(TestQueue, testgetSizeFromQueue) {
    CQueue queue;
    queue.enqueue(11);
    queue.enqueue(22);
    queue.enqueue(33);
    queue.enqueue(44);

    ASSERT_EQ(queue.getSize(), 4);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}