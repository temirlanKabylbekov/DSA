#include <iostream>
#include "assert.h"

/*
    Сортировка выбором:
        алгоритмическая сложность - O(n^2), O(n) - в лучшем случае(когда массив отсортирован изначально)
        дополнительная память - O(1)
        устойчивая
    
    Алгоритм:
        * у нас есть левая отсортированная и правая неупорядоченная
        * берем первый элемент правой части
        * и находим ей подходящее место в левой части, сдвигая оставшиеся справа элементы вправо

*/
void insertionSort(int* arr, int n);

void insertionSort(int* arr, int n) {
    assert(n > 0 && "array is empty");

    for(int border = 1; border < n; border++) {
        int i = border - 1;
        int borderIndex = border;
        while(i >= 0 && arr[i] > arr[borderIndex]) {
            std::swap(arr[i], arr[borderIndex]);
            borderIndex = i--;
        }
    }
}