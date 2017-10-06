#include "main.cpp"
#include <gtest/gtest.h>


void compareArrays(int* sorted, int* expected, int n) {
    for (int i = 0; i < n; i++) {
        EXPECT_EQ(sorted[i], expected[i]);
    }
    delete[] expected;
    delete[] sorted;
}


TEST(bubbleSortTest, NonPositiveElementsCount) {
    int* arr = new int[5];
    ASSERT_DEATH(bubbleSort(arr, 0);, "array is empty");
    delete[] arr;
}

TEST(bubbleSortTest, SingleElementArray) {
    int* arr = new int[5]{11};
    bubbleSort(arr, 1);

    int* expected = new int[5]{11};
    compareArrays(arr, expected, 5);
}

TEST(bubbleSortTest, SortReversedArray) {
    int* arr = new int[100]{5, 4, 3, 2, 1};
    bubbleSort(arr, 5);

    int* expected = new int[5]{1, 2, 3, 4, 5};
    compareArrays(arr, expected, 5);
}

TEST(bubbleSortTest, SortMinArrayElementIsFirst) {
    int* arr = new int[5]{1, 4, 5, 3, 2};
    bubbleSort(arr, 5);

    int* expected = new int[5]{1, 2, 3, 4, 5};
    compareArrays(arr, expected, 5);
}

TEST(bubbleSortTest, SortMaxArrayElementIsLast) {
    int* arr = new int[5]{1, 4, 2, 3, 5};
    bubbleSort(arr, 5);

    int* expected = new int[5]{1, 2, 3, 4, 5};
    compareArrays(arr, expected, 5);
}

TEST(bubbleSortTest, SortSortedArray) {
    int* arr = new int[10]{1, 2, 3, 4, 5};
    bubbleSort(arr, 5);

    int* expected = new int[5]{1, 2, 3, 4, 5};
    compareArrays(arr, expected, 5);
}

TEST(bubbleSortTest, PlainSort) {
    int* arr = new int[10]{2, 5, 3, 1, 4};
    bubbleSort(arr, 5);

    int* expected = new int[5]{1, 2, 3, 4, 5};
    compareArrays(arr, expected, 5);
}


TEST(bubbleSortOptimizedTest, NonPositiveElementsCount) {
    int* arr = new int[5];
    ASSERT_DEATH(bubbleSortOptimized(arr, 0);, "array is empty");
    delete[] arr;
}

TEST(bubbleSortOptimizedTest, SingleElementArray) {
    int* arr = new int[5]{11};
    bubbleSortOptimized(arr, 1);

    int* expected = new int[5]{11};
    compareArrays(arr, expected, 5);
}

TEST(bubbleSortOptimizedTest, SortReversedArray) {
    int* arr = new int[100]{5, 4, 3, 2, 1};
    bubbleSortOptimized(arr, 5);

    int* expected = new int[5]{1, 2, 3, 4, 5};
    compareArrays(arr, expected, 5);
}

TEST(bubbleSortOptimizedTest, SortMinArrayElementIsFirst) {
    int* arr = new int[5]{1, 4, 5, 3, 2};
    bubbleSortOptimized(arr, 5);

    int* expected = new int[5]{1, 2, 3, 4, 5};
    compareArrays(arr, expected, 5);
}

TEST(bubbleSortOptimizedTest, SortMaxArrayElementIsLast) {
    int* arr = new int[5]{1, 4, 2, 3, 5};
    bubbleSortOptimized(arr, 5);

    int* expected = new int[5]{1, 2, 3, 4, 5};
    compareArrays(arr, expected, 5);
}

TEST(bubbleSortOptimizedTest, SortSortedArray) {
    int* arr = new int[10]{1, 2, 3, 4, 5};
    bubbleSortOptimized(arr, 5);

    int* expected = new int[5]{1, 2, 3, 4, 5};
    compareArrays(arr, expected, 5);
}

TEST(bubbleSortOptimizedTest, PlainSort) {
    int* arr = new int[10]{2, 5, 3, 1, 4};
    bubbleSortOptimized(arr, 5);

    int* expected = new int[5]{1, 2, 3, 4, 5};
    compareArrays(arr, expected, 5);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}