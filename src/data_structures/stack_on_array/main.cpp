#include <iostream>
#include <assert.h>
/*
    Стэк на массиве (можно и на односвязном списке)
    Стэк - СД, работающая по принципу LIFO(last in - first out)

    Голова стэка - последний добавленный элемент в стэк
    Операции над стэком:
        * push (положить в стэк)
        * pop (удалить из стэка)
        * peek (прочитать голову стэка)
    
    Применение стэка:
        вычисления выражении (например, калькулятор с обратной польской нотацией)
        вызов функции (например, рекурсия хранится в стэке)
        проверка закрытия/открытия скобок
*/


class CStack {
public:
    explicit CStack(int _bufferSize);
    ~CStack();
    
    /* Добавление нового элемента в голову стэка:
        Алгоритмическая сложность: O(1)
    */
    void push(int data);
    /* Возврат и удаление головного элемента стэка:
        Алгоритмическая сложность: O(1)
    */
    int pop();
    /* Чтение головного элемента стэка:
        Алгоритмическая сложность: O(1)
    */
    int peek();
    /* Получение размера стэка:
        Алгоритмическая сложность: O(1)
    */
    int getSize();
private:
    int* buffer;
    int bufferSize;
    int top; // индекс головного элемента стэка
};

CStack::CStack(int _bufferSize) : bufferSize(_bufferSize), top(-1) {
    buffer = new int[bufferSize];
}

CStack::~CStack() {
    delete[] buffer;
}

void CStack::push(int data) {
    assert(top < bufferSize - 1 && "the size of buffer reached maximum");
    buffer[++top] = data;
}

int CStack::pop() {
    assert(top != -1 && "stack is empty");
    return buffer[top--];
}

int CStack::peek() {
    assert(top != -1 && "stack is empty");
    return buffer[top];
}

int CStack::getSize() {
    return top + 1;
}
