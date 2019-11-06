#ifndef LINKEDLIST_LINKEDLIST_HPP
#define LINKEDLIST_LINKEDLIST_HPP

#include <iostream>
#include "Node.hpp"
#include "Iterator.hpp"

template <class T>
class LinkedList{
private:
    Node<T>* head;
    Node<T>* last;
    int size;
    void deleteall(Node<T>*);
    void copy(const LinkedList&);
public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList&);
    LinkedList& operator=(const LinkedList&);

    void pushEnd(T);
    void pushFront(T);
    void popEnd();
    void popFront();

    const int getSize() const;
    void print();

    friend class Iterator<T>;
    Iterator<T> begin();
    Iterator<T> end();
};

template <class T>
Iterator<T> LinkedList<T>::begin() {
    return Iterator<T>(this->head);
}

template <class T>
Iterator<T> LinkedList<T>::end() {
    return Iterator<T>(nullptr);
}

template <class T>
const int LinkedList<T>::getSize() const {
    return this->size;
}

template <class T>
void LinkedList<T>::print() {
        Node<T> *crr = this->head;
        while (crr != nullptr) {
            std::cout << crr->data << std::endl;
            crr = crr->next;
        }
}

template <class T>
LinkedList<T>::LinkedList() {
    this->head=nullptr;
    this->last= nullptr;
    this->size=0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList& other) {
    this->copy(other);
}

template <class T>
 LinkedList<T>& LinkedList<T>::operator=(const LinkedList &other) {
    if(this!=&other){
        this->deleteall(this->head);
        this->copy(other);
    }
    return *this;
}

template <class T>
void LinkedList<T>::deleteall(Node<T>* a){
    if(a == nullptr){
        return;
    }
    deleteall(a->next);
    delete a;
}

template <class T>
LinkedList<T>::~LinkedList() {
    deleteall(this->head);
}

template <class T>
void LinkedList<T>::pushFront(T data) {
    if(this->head==nullptr){
        this->head=new Node(data);
        this->last=this->head;
    }else{
        Node<T>* newNode = new Node(data);
        newNode->next=this->head;
        this->head=newNode;
    }
    ++size;
}

template <class T>
void LinkedList<T>::pushEnd(T data) {
    if(this->last==nullptr){
        this->head=new Node(data);
        this->last=this->head;
    }else{
        this->last->next = new Node<T>(data, this->last);
        this->last = this->last->next;
    }
    ++size;
}

template <class T>
void LinkedList<T>::popEnd() {
    if(this->last==nullptr){
        return;
    }else{
        if(this->last->previous==nullptr){
            delete this->head;
            this->head=nullptr;
        }else{
            Node<T>* crr = this->last->previous;
            delete this->last;
            this->last=crr;
            this->last->next=nullptr;
        }
        --size;
    }
}

template <class T>
void LinkedList<T>::popFront() {
    if(this->head==nullptr){
        return;
    }else{
        if(this->head->next==nullptr){
            delete this->head;
            this->head=nullptr;
        }else{
            Node<T>* crr = this->head->next;
            delete this->head;
            this->head=crr;
            this->head->previous=nullptr;
        }
        --size;
    }
}

template <class T>
void LinkedList<T>::copy(const LinkedList &other) {
    Node<T>* crr = other.head;
    while(crr!=nullptr){
        this->pushEnd(other.head->data);
        crr=crr->next;
    }
}

#endif //LINKEDLIST_LINKEDLIST_HPP
