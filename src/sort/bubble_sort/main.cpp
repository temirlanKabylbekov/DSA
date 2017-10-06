#include <iostream>
#include "assert.h"

/*
    Сортировка пузырьком:
        Алгоритмическая сложность - O(n^2)
        Дополнительная память - O(1)
        Устойчивая
    
    Алгоритм:
        * Берем элемент из левой части массива
        * Сравниваем с правым соседом
        * Если он больше, то меняем их местами
        * Берем второй элемент массива
        * go to 1
        * делаем до тех пор, пока максимальный элемент из левой части не всплывет в конец
*/
void bubbleSort(int* arr, int n);

/*
    Алгоритмическая сложность - O(n) в лучшем случае, если массив изначально отсортирован
*/
void bubbleSortOptimized(int* arr, int n);


void bubbleSort(int* arr, int n) {
    assert(n > 0 && "array is empty");

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}


void bubbleSortOptimized(int* arr, int n) {
    assert(n > 0 && "array is empty");

    bool swapEvent = false;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swapEvent = true;
                std::swap(arr[j], arr[j + 1]);
            }
        }
        if (!swapEvent) {
            break;
        }
    }
}