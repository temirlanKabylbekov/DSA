#include <iostream>
#include "assert.h"
/*
    Очередь - СД, работающая по принципу FIFO(first in - first out)
    Можно реализовать на массиве, и на списке.

    Основные методы:
        enqueue - положить данные в очередь
        dequeue - извлечь данные из очереди
    
    Помимо стэка и очереди, есть также СД дэк.
    Он реализует как FIFO, так и LIFO принципы:
        pushBack
        popBack
        pushFront
        popFront
*/


struct CNode {
    int data;
    CNode* next;

    CNode(): data(0), next(NULL) {}
};


class CQueue{
public:
    explicit CQueue();
    ~CQueue();

    /*Алгоритмическая сложность: O(1)*/
    void enqueue(int data);
    /*Алгоритмическая сложность: O(1)*/
    int dequeue();
    int getSize();
private:
    CNode* head; // ссылка на головной элемент очереди
    CNode* tail; // ссылка на последний элемент очереди (последний добавленный)
};


CQueue::CQueue() {
    head = NULL;
    tail = NULL;
}

CQueue::~CQueue() {
    CNode* current = head;
    while (current != NULL) {
        current = current -> next;
        delete current;
    }
}

void CQueue::enqueue(int data) {
    CNode* newNode = new CNode();
    newNode -> data = data;

    if (head == NULL) {
        head = newNode;
    } else {
        tail -> next = newNode;
    }
    tail = newNode;
}

int CQueue::dequeue() {
    assert(head != NULL && "queue is empty");

    int headData = head -> data;
    head = head -> next;
    return headData;
}

int CQueue::getSize() {
    int size = 0;
    CNode* current = head;
    while (current != NULL) {
        current = current -> next;
        size++;
    }
    return size;
}
