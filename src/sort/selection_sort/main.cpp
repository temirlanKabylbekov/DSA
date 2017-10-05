#include <iostream>
#include "assert.h"

/*Квадратичная сортировка - Сортировка выбором
    Алгоритмическая сложность - O(n^2)
    Дополнительная память - O(1) - локальный тип сортировки
    Неустойчивая

  Алгоритм:
    Массив разделен на 2 части: левая уже отсортирована, правая еще нет
    * ищем минимум в правой части
    * меняем его с первым элементом правой части
    * сдвигаем границу разделения вправо на 1
*/
void selectionSort(int* arr, int n);

void selectionSort(int* arr, int n) {
    assert(n > 0 && "array is empty");

    int border = 0;
    int minIndex;

    while (border < n - 1) {
        minIndex = border;
        for(int i = border + 1; i < n; i++) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
        }
        std::swap(arr[border], arr[minIndex]);
        border++;
    }
}
