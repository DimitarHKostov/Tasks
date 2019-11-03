#pragma once
#include "Node.h"
#include "Iterator.h"

class LinkedList{
private:
    Node* head;
    Node* last;
    int size;
    void deleteall(Node*);
    void copy(const LinkedList&);
public:
    LinkedList();
    LinkedList(const LinkedList&);
    LinkedList& operator=(const LinkedList&);
    ~LinkedList();
    void pushFront(int);
    void pushEnd(int);
    void popFront();
    void popEnd();
    void print();
    const int getSize() const;

    friend class Iterator;
    Iterator begin();
    Iterator end();
};
