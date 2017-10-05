#include "main.cpp"
#include <gtest/gtest.h>


void compareArrays(int* sorted, int* expected, int n) {
    for (int i = 0; i < n; i++) {
        EXPECT_EQ(sorted[i], expected[i]);
    }
    delete[] expected;
    delete[] sorted;
}


TEST(selectionSortTest, NonPositiveElementsCount) {
    int* arr = new int[5];
    ASSERT_DEATH(selectionSort(arr, 0);, "array is empty");
    delete[] arr;
}

TEST(selectionSortTest, SingleElementArray) {
    int* arr = new int[5]{11};
    selectionSort(arr, 1);

    int* expected = new int[5]{11};
    compareArrays(arr, expected, 5);
}

TEST(selectionSortTest, SortReversedArray) {
    int* arr = new int[100]{5, 4, 3, 2, 1};
    selectionSort(arr, 5);

    int* expected = new int[5]{1, 2, 3, 4, 5};
    compareArrays(arr, expected, 5);
}

TEST(selectionSortTest, SortMinArrayElementIsFirst) {
    int* arr = new int[5]{1, 4, 5, 3, 2};
    selectionSort(arr, 5);

    int* expected = new int[5]{1, 2, 3, 4, 5};
    compareArrays(arr, expected, 5);
}

TEST(selectionSortTest, SortMaxArrayElementIsLast) {
    int* arr = new int[5]{1, 4, 2, 3, 5};
    selectionSort(arr, 5);

    int* expected = new int[5]{1, 2, 3, 4, 5};
    compareArrays(arr, expected, 5);
}

TEST(selectionSortTest, SortSortedArray) {
    int* arr = new int[10]{1, 2, 3, 4, 5};
    selectionSort(arr, 5);

    int* expected = new int[5]{1, 2, 3, 4, 5};
    compareArrays(arr, expected, 5);
}

TEST(selectionSortTest, PlainSort) {
    int* arr = new int[10]{2, 5, 3, 1, 4};
    selectionSort(arr, 5);

    int* expected = new int[5]{1, 2, 3, 4, 5};
    compareArrays(arr, expected, 5);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}