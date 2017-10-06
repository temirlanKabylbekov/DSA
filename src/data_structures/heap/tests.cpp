#include "main.cpp"
#include <gtest/gtest.h>


/* GET SIZE TESTS */
TEST(TestHeap, testGetSizeOfEmptyHeap) {
    CHeap heap(10);
    ASSERT_EQ(heap.getSize(), 0);
}

TEST(TestHeap, testGetSizeOfHeap) {
    CHeap heap(10);
    heap.add(111);
    heap.add(222);
    heap.add(333);
    ASSERT_EQ(heap.getSize(), 3);
}

TEST(TestHeap, testGetSizeOfMemoryRelocatedHeap) {
    CHeap heap(1);
    heap.add(111);
    heap.add(222);
    heap.add(333);
    ASSERT_EQ(heap.getSize(), 3);
}

TEST(TestHeap, testGetSizeAfterExtractingRoot) {
    CHeap heap(10);
    heap.add(111);
    heap.add(222);
    heap.add(333);
    heap.popRoot();
    heap.popRoot();
    ASSERT_EQ(heap.getSize(), 1);
}

/* ADD TO HEAP TESTS */
TEST(TestHeap, testAddToEmptyHeap) {
    CHeap heap(10);
    heap.add(101);
    ASSERT_EQ(heap.popRoot(), 101);
}

TEST(TestHeap, testAddToOversizedHeap) {
    CHeap heap(2);
    heap.add(101);
    heap.add(202);
    heap.add(303);
    ASSERT_EQ(heap.popRoot(), 303);
}

TEST(TestHeap, testAddAfterPopRoot) {
    CHeap heap(2);
    heap.add(303);
    heap.add(202);
    heap.add(101);
    heap.popRoot();
    ASSERT_EQ(heap.popRoot(), 202);
}

/* POP ROOT TESTS */
TEST(TestHeap, testPopRootFromEmptyHeap) {
    CHeap heap(2);
    ASSERT_DEATH(heap.popRoot();, "the heap is empty");
}


class TestCHeap : public CHeap {
public:
    TestCHeap(unsigned long _reservedSize): CHeap(_reservedSize) {}

    /* flex to mock buffer */
    void setBuffer(std::vector<long> _buffer) {
        buffer = _buffer;
        size = buffer.size();
    }

    std::vector<long> getBuffer() {
        return buffer;
    }

    void siftUp(unsigned long index) {
        return CHeap::siftUp(index);
    }

    void siftDown(unsigned long index) {
        return CHeap::siftDown(index);
    }

    void buildHeap() {
        return CHeap::buildHeap();
    }
};


/* SIFT UP TESTS */
TEST(TestPrivateHeap, testSiftUpForSingleNodeHeap) {
    TestCHeap heap(10);
    
    static const long arr[] = {322};
    std::vector<long> buffer(arr, arr + sizeof(arr) / sizeof(arr[0]));
    heap.setBuffer(buffer);

    heap.siftUp(0);

    ASSERT_EQ(heap.getBuffer(), buffer);
}

TEST(TestPrivateHeap, testSiftUpByIndexIsOutOfRange) {
    TestCHeap heap(10);

    static const long arr[] = {322};
    std::vector<long> buffer(arr, arr + sizeof(arr) / sizeof(arr[0]));
    heap.setBuffer(buffer);

    ASSERT_DEATH(heap.siftUp(2);, "index is out of range");
}

TEST(TestPrivateHeap, testSiftUp) {
    TestCHeap heap(10);
    
    static const long arr[] = {1, 2, 3, 4};
    std::vector<long> buffer(arr, arr + sizeof(arr) / sizeof(arr[0]));
    heap.setBuffer(buffer);
    
    heap.siftUp(3);

    static const long exp[] = {4, 1, 3, 2};
    std::vector<long> expBuf(exp, exp + sizeof(exp) / sizeof(exp[0]));
    ASSERT_EQ(heap.getBuffer(), expBuf);
}

TEST(TestPrivateHeap, testSiftUpBuiltHeap) {
    TestCHeap heap(10);
    
    static const long arr[] = {4, 3, 2, 1};
    std::vector<long> buffer(arr, arr + sizeof(arr) / sizeof(arr[0]));
    heap.setBuffer(buffer);
    
    heap.siftUp(3);

    static const long exp[] = {4, 3, 2, 1};
    std::vector<long> expBuf(exp, exp + sizeof(exp) / sizeof(exp[0]));
    ASSERT_EQ(heap.getBuffer(), expBuf);
}

/* SIFT DOWN TESTS */
TEST(TestPrivateHeap, testSiftDownForSingleNodeHeap) {
    TestCHeap heap(10);
    
    static const long arr[] = {322};
    std::vector<long> buffer(arr, arr + sizeof(arr) / sizeof(arr[0]));
    heap.setBuffer(buffer);

    heap.siftDown(0);

    ASSERT_EQ(heap.getBuffer(), buffer);
}

TEST(TestPrivateHeap, testSiftDownByIndexIsOutOfRange) {
    TestCHeap heap(10);

    static const long arr[] = {322};
    std::vector<long> buffer(arr, arr + sizeof(arr) / sizeof(arr[0]));
    heap.setBuffer(buffer);

    ASSERT_DEATH(heap.siftDown(2);, "index is out of range");
}

TEST(TestPrivateHeap, testSiftDown) {
    TestCHeap heap(10);
    
    static const long arr[] = {1, 2, 3, 4};
    std::vector<long> buffer(arr, arr + sizeof(arr) / sizeof(arr[0]));
    heap.setBuffer(buffer);
    
    heap.siftDown(0);

    static const long exp[] = {3, 2, 1, 4};
    std::vector<long> expBuf(exp, exp + sizeof(exp) / sizeof(exp[0]));
    ASSERT_EQ(heap.getBuffer(), expBuf);
}

TEST(TestPrivateHeap, testSiftDownBuiltHeap) {
    TestCHeap heap(10);
    
    static const long arr[] = {4, 3, 2, 1};
    std::vector<long> buffer(arr, arr + sizeof(arr) / sizeof(arr[0]));
    heap.setBuffer(buffer);
    
    heap.siftDown(1);

    static const long exp[] = {4, 3, 2, 1};
    std::vector<long> expBuf(exp, exp + sizeof(exp) / sizeof(exp[0]));
    ASSERT_EQ(heap.getBuffer(), expBuf);
}

TEST(TestPrivateHeap, testSiftDownLeafNode) {
    TestCHeap heap(10);
    
    static const long arr[] = {4, 3, 2, 1};
    std::vector<long> buffer(arr, arr + sizeof(arr) / sizeof(arr[0]));
    heap.setBuffer(buffer);
    
    heap.siftDown(2);

    static const long exp[] = {4, 3, 2, 1};
    std::vector<long> expBuf(exp, exp + sizeof(exp) / sizeof(exp[0]));
    ASSERT_EQ(heap.getBuffer(), expBuf);
}


/* BUILD HEAP TESTS */
TEST(TestPrivateHeap, testBuildHeapSingleNodeHeap) {
    TestCHeap heap(10);
    
    static const long arr[] = {100500};
    std::vector<long> buffer(arr, arr + sizeof(arr) / sizeof(arr[0]));
    heap.setBuffer(buffer);

    heap.buildHeap();

    static const long exp[] = {100500};
    std::vector<long> expBuf(exp, exp + sizeof(exp) / sizeof(exp[0]));
    ASSERT_EQ(heap.getBuffer(), expBuf);
}

TEST(TestPrivateHeap, testBuildEmptyHeap) {
    TestCHeap heap(10);
    heap.buildHeap();
}

TEST(TestPrivateHeap, testBuildHeapMaxElementsAtTheBottom) {
    TestCHeap heap(10);
    
    static const long arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<long> buffer(arr, arr + sizeof(arr) / sizeof(arr[0]));
    heap.setBuffer(buffer);

    heap.buildHeap();

    static const long exp[] = {8, 7, 6, 3, 4, 5, 2, 1, 0};
    std::vector<long> expBuf(exp, exp + sizeof(exp) / sizeof(exp[0]));
    ASSERT_EQ(heap.getBuffer(), expBuf);
}

TEST(TestPrivateHeap, testBuildHBuitHeap) {
    TestCHeap heap(10);
    
    static const long arr[] = {8, 7, 6, 3, 4, 5, 2, 1, 0};
    std::vector<long> buffer(arr, arr + sizeof(arr) / sizeof(arr[0]));
    heap.setBuffer(buffer);

    heap.buildHeap();

    static const long exp[] = {8, 7, 6, 3, 4, 5, 2, 1, 0};
    std::vector<long> expBuf(exp, exp + sizeof(exp) / sizeof(exp[0]));
    ASSERT_EQ(heap.getBuffer(), expBuf);
}

TEST(TestPrivateHeap, testBuildHeapMaxElementsAtTheTop) {
    TestCHeap heap(10);
    
    static const long arr[] = {7, 8, 0, 3, 5, 4, 6, 1, 2};
    std::vector<long> buffer(arr, arr + sizeof(arr) / sizeof(arr[0]));
    heap.setBuffer(buffer);

    heap.buildHeap();

    static const long exp[] = {8, 7, 6, 3, 5, 4, 0, 1, 2};
    std::vector<long> expBuf(exp, exp + sizeof(exp) / sizeof(exp[0]));
    ASSERT_EQ(heap.getBuffer(), expBuf);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}