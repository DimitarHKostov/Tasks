#ifndef LINKEDLIST_ITERATOR_HPP
#define LINKEDLIST_ITERATOR_HPP
#include <cassert>
#include "Node.hpp"

template <class T>
class LinkedList;

template <class T>
class Iterator {
private:
    Node<T>* obj;
    Iterator(Node<T>* start);
public:
    T& operator*();
    bool operator==(const Iterator<T>&) const;
    bool operator!=(const Iterator<T>&) const;
    Iterator<T>& operator++();

    friend class LinkedList<T>;
};

template <class T>
Iterator<T>::Iterator(Node<T> *start) {
    this->obj=start;
}

template <class T>
T& Iterator<T>::operator*(){
    return this->obj->data;
}

template <class T>
bool Iterator<T>::operator==(const Iterator<T> &other) const {
    return this->obj==other.obj;
}

template <class T>
bool Iterator<T>::operator!=(const Iterator<T> &other) const {
    return this->obj!=other.obj;
}

template <class T>
Iterator<T>& Iterator<T>::operator++() {
    assert(this->obj!=nullptr);
    this->obj=this->obj->next;
    return *this;
}

#endif //LINKEDLIST_ITERATOR_HPP
