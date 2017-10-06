#include "main.cpp"
#include <gtest/gtest.h>


void compareArrays(int* sorted, int* expected, int n) {
    for (int i = 0; i < n; i++) {
        EXPECT_EQ(sorted[i], expected[i]);
    }
    delete[] expected;
    delete[] sorted;
}


TEST(insertionSortTest, NonPositiveElementsCount) {
    int* arr = new int[5];
    ASSERT_DEATH(insertionSort(arr, 0);, "array is empty");
    delete[] arr;
}

TEST(insertionSortTest, SingleElementArray) {
    int* arr = new int[5]{11};
    insertionSort(arr, 1);

    int* expected = new int[5]{11};
    compareArrays(arr, expected, 5);
}

TEST(insertionSortTest, SortReversedArray) {
    int* arr = new int[100]{5, 4, 3, 2, 1};
    insertionSort(arr, 5);

    int* expected = new int[5]{1, 2, 3, 4, 5};
    compareArrays(arr, expected, 5);
}

TEST(insertionSortTest, SortMinArrayElementIsFirst) {
    int* arr = new int[5]{1, 4, 5, 3, 2};
    insertionSort(arr, 5);

    int* expected = new int[5]{1, 2, 3, 4, 5};
    compareArrays(arr, expected, 5);
}

TEST(insertionSortTest, SortMaxArrayElementIsLast) {
    int* arr = new int[5]{1, 4, 2, 3, 5};
    insertionSort(arr, 5);

    int* expected = new int[5]{1, 2, 3, 4, 5};
    compareArrays(arr, expected, 5);
}

TEST(insertionSortTest, SortSortedArray) {
    int* arr = new int[10]{1, 2, 3, 4, 5};
    insertionSort(arr, 5);

    int* expected = new int[5]{1, 2, 3, 4, 5};
    compareArrays(arr, expected, 5);
}

TEST(insertionSortTest, PlainSort) {
    int* arr = new int[10]{2, 5, 3, 1, 4};
    insertionSort(arr, 5);

    int* expected = new int[5]{1, 2, 3, 4, 5};
    compareArrays(arr, expected, 5);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}