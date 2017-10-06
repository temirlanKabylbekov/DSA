#include <iostream>
#include <vector>
#include "assert.h"

/*
    Двоичная куча - двоичное дерево, которое удовлетворяет следующим условиям:
        * значение в любой его вершине не меньше, чем значения у его потомков
        * глубина листье различается не больше, чем на 1
        * последний слой заполняется слево направо
    
    Глубина кучи = O(log N)

    Двоичная куча хранится в массиве(
           [(i-1)/2] - родитель
              |
              i
            /   \
        2*i+1   2*i+2 - дети
    )
*/
class CHeap {
public:
    explicit CHeap(unsigned long _reservedSize);
    ~CHeap();

    void add(long element);
    long popRoot();

    unsigned long getSize();

protected:
    /*"всплытие" элемента, алгоритмическая сложность O(log n), дополнительная память - O(1)*/
    void siftUp(unsigned long index);
    /*"топим" элемент, лгоритмическая сложность O(log n), дополнительная память - O(1)*/
    void siftDown(unsigned long index);
    /*алгоритмическая сложность O(n log n), дополнительная память - O(1)*/
    void buildHeap();

    std::vector<long> buffer;
    long size;
};

CHeap::CHeap(unsigned long _reservedSize) {
    buffer.reserve(_reservedSize);
    size = 0;
}

CHeap::~CHeap() {
    buffer.clear();
}

void CHeap::siftDown(unsigned long index) {
    assert(index < size && "index is out of range");

    unsigned long largest = index;
    if (2 * index + 1 < size && buffer[2 * index + 1] > buffer[largest]) {
        largest = 2 * index + 1;
    }
    if (2 * index + 2 < size && buffer[2 * index + 2] > buffer[largest]) {
        largest = 2 * index + 2;
    }
    
    if (largest != index) {
        std::swap(buffer[largest], buffer[index]);
        this -> siftDown(largest);
    }
}

void CHeap::siftUp(unsigned long index) {
    assert(index < size && "index is out of range");

    unsigned long parent;
    while (index > 0) {
        parent = (index - 1) / 2;
        if (buffer[index] <= buffer[parent]) {
            break;
        }
        std::swap(buffer[index], buffer[parent]);
        index = parent;        
    }
}

void CHeap::buildHeap() {
    for (long i = size / 2 - 1; i >= 0; i--) {
        this -> siftDown(i);
    }
}

void CHeap::add(long element) {
    buffer.push_back(element);
    this -> siftUp(size++);
}

long CHeap::popRoot() {
    assert(size > 0 && "the heap is empty");

    long root = buffer[0];
    std::swap(buffer[0], buffer[size - 1]);
    
    buffer.pop_back();
    size--;

    if (size > 0) {
        this -> siftDown(0);
    }
    return root;
}

unsigned long CHeap::getSize() {
    return size;
}
