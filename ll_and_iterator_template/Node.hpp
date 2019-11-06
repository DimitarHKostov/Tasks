#ifndef LINKEDLIST_NODE_HPP
#define LINKEDLIST_NODE_HPP

template <class T>
struct Node{
    T data;
    Node<T>* next;
    Node<T>* previous;
    Node(T data, Node<T>* previous=nullptr, Node<T>* next=nullptr):data(data), previous(previous), next(next){}
};

#endif //LINKEDLIST_NODE_HPP
