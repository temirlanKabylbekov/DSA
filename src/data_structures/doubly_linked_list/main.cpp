#include <iostream>
#include <assert.h>
/*
    Двусвязанный список:
        Преимущества над массивом:
            + динамически растущая без нашего вмешательства СД, ограниченная лишь памятью компьютера
            + быстрая и динамическая вставка
            + быстрое и динамическое удаление
        Недостатки над массивом:
            - данные хранятся в памяти разреженно - нет кеширования
            - нет прямого доступа - доступа по индексу
            - расходуется доп память на хранение данных, линкующих с соседними узлами
    
    Для работы со списками нужно иметь указатель на "голову" в случае односвязного,
    "голову" и "хвост" в случае двусвязного списка.
*/
struct CNode {
    int data;
    CNode* prev;
    CNode* next;

    CNode(): data(0), prev(0), next(0) {}
};


/*
    Поиск элемента списка:
        возвращает указатель на найденный узел в списке
        алгоритмическая сложность O(n) в худшем случае
        необходимая дополнительная память O(1)
*/
CNode* search(CNode* head, int a);

/*
    Вставка элемента в список:
        возвращает указатель на вставленный элемент
        алгоритмическая сложность O(1)
        необходимая дополнительная память 0
*/
CNode* insertAfter(CNode* node, int a);

/*
    Вставка элемента в список:
        возвращает указатель на вставленный элемент
        алгоритмическая сложность O(1)
        необходимая дополнительная память 0
*/
CNode* insertBefore(CNode* node, int a);

/*
    Удаление элемента списка:
        алгоритмическая сложность O(1)
        необходимая дополнительная память 0
*/
void deleteAt(CNode* node);

/*
   Объединение 2-х связанных списков:
        возвращает указатель на начало объединенного списка:
        алгоритмическая сложность O(n), где n - длина первого списка
        необходимая дополнительная память O(1)
*/
CNode* unify(CNode* head1, CNode* head2);


CNode* search(CNode* head, int a) {
    assert(head != NULL && "passed list head is null");

    CNode* current = head;
    while(current != NULL) {
        if (current -> data == a) {
            return current;
        }
        current = current -> next;
    }
    return NULL;
}

CNode* insertAfter(CNode* node, int a) {
    assert(node != NULL && "you are trying to add new node after null one");

    CNode* inserted = new CNode();
    inserted -> prev = node;
    inserted -> data = a;
    inserted -> next = node -> next;

    if (node -> next != NULL) {        
        inserted -> next -> prev = inserted;
    }
    node -> next = inserted;
    return inserted;
}

CNode* insertBefore(CNode* node, int a) {
    assert(node != NULL && "you are trying to add new node before null one");
    
    CNode* newNode = new CNode();
    newNode -> data = a;
    newNode -> next = node;
    
    if (node -> prev != NULL) {
        newNode -> prev = node -> prev;
        node -> prev -> next = newNode;
    }

    node -> prev = newNode;
    return newNode;
}

void deleteAt(CNode* node) {
    assert(node != NULL && "you are trying delete null node");

    if (node -> prev != NULL) {
        node -> prev -> next = node -> next;
    }
    if (node -> next != NULL) {
        node -> next -> prev = node -> prev;
    }
    delete node;
}

CNode* unify(CNode* head1, CNode* head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    CNode* current = head1;
    while(current != NULL) {
        if (current -> next == NULL) {
            current -> next = head2;
            head2 -> prev = current;
            break;
        }
        current = current -> next;
    }
    return head1;
}
